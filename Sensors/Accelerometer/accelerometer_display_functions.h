#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_FXOS8700.h>

/* Assign a unique ID to this sensor at the same time */
Adafruit_FXOS8700 accelmag = Adafruit_FXOS8700(0x8700A, 0x8700B);

void displayAccSensorDetails(void)
{
  sensor_t accel, mag;
  accelmag.getSensor(&accel, &mag);
  Serial.println("------------------------------------");
  Serial.println("ACCELEROMETER");
  Serial.println("------------------------------------");
  Serial.print  ("Sensor:       "); Serial.println(accel.name);
  Serial.print  ("Driver Ver:   "); Serial.println(accel.version);
  Serial.print  ("Unique ID:    0x"); Serial.println(accel.sensor_id, HEX);
  Serial.print  ("Min Delay:    "); Serial.print(accel.min_delay); Serial.println(" s");
  Serial.print  ("Max Value:    "); Serial.print(accel.max_value, 4); Serial.println(" m/s^2");
  Serial.print  ("Min Value:    "); Serial.print(accel.min_value, 4); Serial.println(" m/s^2");
  Serial.print  ("Resolution:   "); Serial.print(accel.resolution, 8); Serial.println(" m/s^2");
  Serial.println("------------------------------------");
  Serial.println("");
  Serial.println("------------------------------------");
  Serial.println("MAGNETOMETER");
  Serial.println("------------------------------------");
  Serial.print  ("Sensor:       "); Serial.println(mag.name);
  Serial.print  ("Driver Ver:   "); Serial.println(mag.version);
  Serial.print  ("Unique ID:    0x"); Serial.println(mag.sensor_id, HEX);
  Serial.print  ("Min Delay:    "); Serial.print(accel.min_delay); Serial.println(" s");
  Serial.print  ("Max Value:    "); Serial.print(mag.max_value); Serial.println(" uT");
  Serial.print  ("Min Value:    "); Serial.print(mag.min_value); Serial.println(" uT");
  Serial.print  ("Resolution:   "); Serial.print(mag.resolution); Serial.println(" uT");
  Serial.println("------------------------------------");
  Serial.println("");
  delay(500);
}

void displayAccSensorReading(void)

{

  //Serial.println("entering sensor tracking function");
  sensors_event_t aevent, mevent;

  //Serial.println("sensors_event_t initialized");

  /* Get a new sensor event */
  accelmag.getEvent(&aevent, &mevent);

  //Serial.println("accelmag called");

  /* Display the accel results (acceleration is measured in m/s^2) */
    Serial.println("ACCELEROMETER (m/s^2):");
  Serial.print("\tX: "); Serial.println(aevent.acceleration.x, 4);
  Serial.print("\tY: "); Serial.println(aevent.acceleration.y, 4);
  Serial.print("\tZ: "); Serial.println(aevent.acceleration.z, 4);

  /* Display the mag results (mag data is in uTesla) */
    Serial.println("MAGNETOMETER (uT):");
   Serial.print("\tX: "); Serial.println(mevent.magnetic.x, 1);
    Serial.print("\tY: "); Serial.println(mevent.magnetic.y, 1);
   Serial.print("\tZ: "); Serial.println(mevent.magnetic.z, 1);
}
