# Python Weather Tracker (Tkinter GUI)

## Overview
This project is a real-time weather tracker built in **Python** using the **Tkinter** GUI library.  
It retrieves live weather data from the **OpenWeatherMap API**, converting user-provided city names into geographical coordinates and displaying detailed conditions such as:

- Temperature (Celsius or Fahrenheit)
- Feels like temperature
- Humidity
- Pressure
- Wind speed
- Cloudiness
- Visibility
- Local time (adjusted to city’s timezone)
- Sunrise and sunset times

The application features a **clean, responsive interface** for fast user interaction and supports **both metric and imperial** formats.

---

## Features
- 🌦 **Live Weather Data** via OpenWeatherMap API
- 📍 **City Name → Coordinates** automatic geocoding
- ⏱ **Local Clock** based on retrieved timezone
- 🔄 **Unit Toggle** (Celsius / Fahrenheit)
- 📜 **Recent Searches Dropdown** for quick reuse
- 🖥 Built entirely with **Python’s built-in Tkinter library**

---

## Hardware & Software Requirements
- Python 3.x
- Internet connection
- OpenWeatherMap API key (free to obtain at: https://openweathermap.org/api)

### Python Libraries
- `requests`
- `tkinter` *(comes pre-installed with Python)*
- `datetime` *(standard library)*

## How it works
1. **City Input**: The user enters a city name or selects from a dropdown of recent searches.
2.	**Geocoding**: The application sends the city name to OpenWeatherMap’s Geocoding API to retrieve latitude and longitude.
3.	**Weather Request**: These coordinates are used to request real-time weather data from OpenWeatherMap’s Weather API.
4.	**Data Parsing**: The JSON response is parsed to extract temperature, weather conditions, and other details.	5.	Timezone Adjustment: The local time for the city is calculated using the timezone offset returned by the API.
6.	**GUI Update**: All results are displayed in a neatly formatted Tkinter window, with units displayed according to the user’s Celsius/Fahrenheit selection.

## Usage
1. Clone the repository
2. Get your API key from OpeanWeatherMap
3. Run the application
4. **Using the App**:
- Enter your API key
- Enter your City name or select from the **recent searches dropdown**
- Choose your unit preference (**Celsuis** or **Fahrenheit**)
- Click Get Weather to fetch and display results/

## Lessons Learned
- Reverse engineering existing code samples to understand data flow and event handling in Tkinter.
- Implementing REST API integration in Python without external frameworks.
- Parsing and formatting API responses for real-time user display.
- Creating a dropdown history system for user convenience.
- Understanding the interaction between geocoding and weather APIs.
