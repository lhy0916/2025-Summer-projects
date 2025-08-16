// LEGO V8 control: throttle (pot), Start/Stop button, Timed Run (10s)
// Driver: L298N  | ENA=D5 (PWM), IN1=D8, IN2=D9

const int ENA = 5;      // PWM speed to L298N ENA
const int IN1 = 8;      // L298N IN1
const int IN2 = 9;      // L298N IN2

const int POT = A0;     // throttle input (potentiometer)
const int BTN_START = 2; // Start/Stop toggle button -> GND
const int BTN_TIMER = 4; // Timed Run (10s) button -> GND

// Debounce
const unsigned long DB_MS = 200;

// State
bool running = false;
unsigned long lastStartPress = 0, lastTimerPress = 0;

// Timer
bool timerActive = false;
unsigned long timerStart = 0;
const unsigned long TIMER_LEN_MS = 10000;  // 10 seconds

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  // Forward direction
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  pinMode(BTN_START, INPUT_PULLUP); // buttons to GND
  pinMode(BTN_TIMER, INPUT_PULLUP);

  // Optional: uncomment for serial debug
  // Serial.begin(9600);
}

void loop() {
  unsigned long now = millis();

  // --- Start/Stop toggle ---
  if (digitalRead(BTN_START) == LOW && now - lastStartPress > DB_MS) {
    running = !running;
    if (!running) timerActive = false;  // cancel timer when stopping
    lastStartPress = now;
  }

  // --- Timed Run (10s) ---
  if (digitalRead(BTN_TIMER) == LOW && now - lastTimerPress > DB_MS) {
    timerActive = true;
    timerStart = now;
    running = true;  // ensure motor starts
    lastTimerPress = now;
  }
  if (timerActive && now - timerStart >= TIMER_LEN_MS) {
    running = false;
    timerActive = false;
  }

  // --- Throttle from potentiometer ---
  int pwm = 0;
  if (running) {
    int pot = analogRead(POT);        // 0..1023
    pwm = map(pot, 0, 1023, 0, 255);  // 0..255 speed
  }

  analogWrite(ENA, pwm);

  // Optional debug
  // Serial.print("Run: "); Serial.print(running);
  // Serial.print("  Timer: "); Serial.print(timerActive);
  // Serial.print("  PWM: "); Serial.println(pwm);

  delay(5);
}