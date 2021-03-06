#include <ESP8266WiFi.h>
#include "ThingSpeak.h"

#include "config.h"

void sendDataToThingSpeak(float currentTemperature, float currentPressure, float currentHumidity, int averagePM1, int averagePM25, int averagePM4, int averagePM10) {
    if (!(THINGSPEAK_ON)) {
        return;
    }

    WiFiClient client;
    ThingSpeak.begin(client);
	if (strcmp(DUST_MODEL, "Non")) {
		ThingSpeak.setField(1, averagePM1);
    	ThingSpeak.setField(2, averagePM25);
    	ThingSpeak.setField(3, averagePM10);
	}
	if (strcmp(THP_MODEL, "Non")) {
	    ThingSpeak.setField(4, currentTemperature);
	    ThingSpeak.setField(5, currentPressure);
	    ThingSpeak.setField(6, currentHumidity);
	}
    ThingSpeak.writeFields(THINGSPEAK_CHANNEL_ID, THINGSPEAK_API_KEY);
    client.stop();
}
