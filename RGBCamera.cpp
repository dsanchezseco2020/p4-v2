#include "RGBCamera.h"
#include "Sensor.h"
#include <cstdlib>
#include <iostream>
#include <sstream> // Para std::ostringstream

RGBCamera::RGBCamera(bool on, int id) : Sensor(on, id, Sensor::RGB_CAMERA) {
}

std::string RGBCamera::collectData() {
    std::ostringstream imageStream; // Utilizamos un string stream para almacenar la imagen
    if (on_) {
        const int width = 200;
        const int height = 100;

        char* imageStart = new char[width * height];
        char* currentPixel = imageStart;

        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                *currentPixel = '.';
                imageStream << *currentPixel;
                ++currentPixel;
            }
            imageStream << '\n';
        }

        delete[] imageStart;
    } else {
        imageStream << getType() << " Sensor " << id_ << " is OFF\n";
    }

    return imageStream.str();
}

std::ostream& operator<<(std::ostream& os, RGBCamera& camera) {
    os << " ------- " << camera.getType() << " Data id: " << camera.getId() << " ----- " << std::endl;
    os << " -   Status: " << (camera.isOn() ? "ON -" : "OFF -") << std::endl;
    os << " -   Image: \n" << camera.collectData();
    os << " ---------------------------------";
    return os;
}
