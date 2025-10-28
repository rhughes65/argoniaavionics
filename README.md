# argoniaavionics
Avionics code for CSU's Argonia Cup team

Emergency Shutdown Protocol
1. Sensor stops updating or gives bad data
        ↓
2. FaultMonitor detects unhealthy sensor
        ↓
3. handleSensorFailure() tries recovery
        ↓
4. If recovery fails → triggerEmergencyAbort()
        ↓
5. Abort sequence:
   - Cut engines
   - Lock actuators
   - Deploy parachute
   - Switch to ABORT stage
   - Send telemetry alert
        ↓
6. Vehicle descends safely and logs the event
