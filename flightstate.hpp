struct FlightState {
    float time;
    Vector3 position;
    Vector3 velocity;
    Quaternion attitude;
    Vector3 angularRate;
    float altitude;
    bool imuHealthy, gpsHealthy;
};
