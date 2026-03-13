#define PIN_R 18
#define PIN_G 17
#define PIN_B 16

void setup() {
  Serial.begin(115200);

  // Configurar y asignar pines PWM en un solo paso.
  // Probar con: 1000 Hz (más suave para algunos LEDs)
  //             200 Hz (más ruido, menos interferencias)
  //             10000 Hz (más estable, menos audible)
  ledcAttach(PIN_R, 5000, 8);
  ledcAttach(PIN_G, 5000, 8);
  ledcAttach(PIN_B, 5000, 8);

  // Apagar al inicio
  ledcWrite(PIN_R, 0);
  ledcWrite(PIN_G, 0);
  ledcWrite(PIN_B, 0);
}

void loop() {
  // Subida gradual
  for (int brillo = 0; brillo <= 255; brillo++) {
    ledcWrite(PIN_R, brillo);
    ledcWrite(PIN_G, brillo);
    //ledcWrite(PIN_B, brillo); // ← Comentar esta línea para AMARILLO | Dejar para BLANCO
    delay(3); // Cambiar el numero si quiero que   respire más lento (ej: delay 10 y 15)
  }

  Serial.println("ESTADO:1");
  delay(2000);

  // Bajada gradual
  for (int brillo = 255; brillo >= 0; brillo--) {
    ledcWrite(PIN_R, brillo);
    ledcWrite(PIN_G, brillo);
    //ledcWrite(PIN_B, brillo); // ← Comentar esta línea para AMARILLO | Dejar para BLANCO
    delay(5); // Cambiar el numero si quiero que   respire más lento (ej: delay 10 y 15)
  }

  Serial.println("ESTADO:0");
  delay(2000);
}
