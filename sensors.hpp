class Sensors {
public:
    void init();
    void update();

    IMUData getIMU() const;
    GPSData getGPS() const;
    float getBaroAltitude() const;
    bool healthy() const;

private:
    IMUData imu_;
    GPSData gps_;
    float baroAlt_;
    bool healthy_;
};
