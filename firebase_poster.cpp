#include "esphome.h"
#include <HTTPClient.h>

class FirebasePoster : public Component {
  public:
    void send_data_to_firebase(float state_of_charge) {
      HTTPClient http;
      http.begin("https://esp32-2ed9f-default-rtdb.firebaseio.com/your_path.json?auth=v2HEeXenilhVZsinz7xgVe3bfN72");  // Firebase URL
      http.addHeader("Content-Type", "application/json");

      String payload = "{\"state_of_charge\": " + String(state_of_charge) + "}";
      
      int httpResponseCode = http.POST(payload);
      if (httpResponseCode > 0) {
Aaa        ESP_LOGD("custom", "Data sent successfully: %d", httpResponseCode);
      } else {
        ESP_LOGE("custom", "Error sending data: %d", httpResponseCode);
      }
      http.end();  // Free resources
    }
};
