import tkinter as tk
from tkinter import messagebox
import requests
from datetime import datetime, timedelta

# ------------------ Globals ------------------
recent_cities = []

# ------------------ Functions ------------------

def get_coordinates(city_name, api_key):
    geo_url = f"http://api.openweathermap.org/geo/1.0/direct?q={city_name}&limit=1&appid={api_key}"
    response = requests.get(geo_url)
    data = response.json()
    if not data:
        raise ValueError("City not found")
    return data[0]["lat"], data[0]["lon"]

def get_weather():
    city = city_entry.get() or recent_city_var.get()
    api_key = api_key_entry.get()
    units = unit_var.get()

    if not city or not api_key:
        messagebox.showwarning("Input Error", "Please enter both city and API key.")
        return

    try:
        lat, lon = get_coordinates(city, api_key)

        weather_url = f"http://api.openweathermap.org/data/2.5/weather?lat={lat}&lon={lon}&appid={api_key}&units={units}"
        response = requests.get(weather_url)
        data = response.json()

        if data.get("cod") != 200:
            raise Exception(data.get("message", "API error"))

        location = data.get("name", city.title())
        country = data["sys"].get("country", "N/A")
        temp = data["main"]["temp"]
        feels_like = data["main"]["feels_like"]
        pressure = data["main"]["pressure"]
        humidity = data["main"]["humidity"]
        weather = data["weather"][0]["description"].title()
        wind_speed = data["wind"]["speed"]
        visibility = data.get("visibility", "N/A")
        clouds = data["clouds"]["all"]
        timezone_offset = data["timezone"]
        sunrise = datetime.utcfromtimestamp(data["sys"]["sunrise"] + timezone_offset).strftime('%H:%M:%S')
        sunset = datetime.utcfromtimestamp(data["sys"]["sunset"] + timezone_offset).strftime('%H:%M:%S')
        local_time = datetime.utcnow() + timedelta(seconds=timezone_offset)

        temp_unit = "°C" if units == "metric" else "°F"
        speed_unit = "m/s" if units == "metric" else "mph"

        result = (
            f"Location: {location}, {country}\n"
            f"Latitude: {lat}\n"
            f"Longitude: {lon}\n"
            f"Local Time: {local_time.strftime('%Y-%m-%d %H:%M:%S')}\n"
            f"Temperature: {temp}{temp_unit}\n"
            f"Feels Like: {feels_like}{temp_unit}\n"
            f"Condition: {weather}\n"
            f"Humidity: {humidity}%\n"
            f"Pressure: {pressure} hPa\n"
            f"Visibility: {visibility} m\n"
            f"Cloudiness: {clouds}%\n"
            f"Wind Speed: {wind_speed} {speed_unit}\n"
            f"Sunrise: {sunrise}\n"
            f"Sunset: {sunset}"
        )

        result_label.config(text=result)

        if city not in recent_cities:
            recent_cities.insert(0, city)
            if len(recent_cities) > 5:
                recent_cities.pop()
            recent_city_var.set(city)
            update_recent_dropdown()

    except Exception as e:
        messagebox.showerror("Error", str(e))
        result_label.config(text="")

def update_recent_dropdown():
    menu = recent_dropdown["menu"]
    menu.delete(0, "end")
    for city in recent_cities:
        menu.add_command(label=city, command=lambda value=city: recent_city_var.set(value))

# ------------------ GUI ------------------

root = tk.Tk()
root.title("Weather Tracker")
root.geometry("600x620")  # Increased window size

tk.Label(root, text="Enter OpenWeatherMap API Key:").pack(pady=5)
api_key_entry = tk.Entry(root, width=50, show="*")
api_key_entry.pack(pady=5)

tk.Label(root, text="Enter City Name:").pack(pady=5)
city_entry = tk.Entry(root, width=35)
city_entry.pack(pady=5)

recent_city_var = tk.StringVar()
recent_city_var.set("Choose recent city")
tk.Label(root, text="Or select from recent searches:").pack(pady=5)
recent_dropdown = tk.OptionMenu(root, recent_city_var, "")
recent_dropdown.pack(pady=5)

unit_var = tk.StringVar(value="metric")
tk.Label(root, text="Choose Units:").pack(pady=5)
tk.Radiobutton(root, text="Celsius (°C)", variable=unit_var, value="metric").pack()
tk.Radiobutton(root, text="Fahrenheit (°F)", variable=unit_var, value="imperial").pack()

tk.Button(root, text="Get Weather", command=get_weather).pack(pady=10)

result_label = tk.Label(root, text="", font=("Arial", 15), wraplength=560, justify="left")
result_label.pack(pady=10)

root.mainloop()