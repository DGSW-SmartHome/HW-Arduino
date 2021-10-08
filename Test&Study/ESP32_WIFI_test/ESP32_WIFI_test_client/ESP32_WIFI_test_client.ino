// FileName : ESP32_WIFI_test_client.ino
// Describe : ESP32를 이용한 AP통신 테스트
// History : 2021-10-07 JAH 
// --------------------------------------------------------------------
#include <WiFi.h>

#define AP_ssid "Seven_Labs"                  // WIFI NAME
#define AP_password "7777Labs"                // WIFI PASSWORD
#define host "192.168.0.41"                   // server IP Address
#define port 80                               // server port

IPAddress server(192,168,0,41);               // server IP Address
WiFiClient client;                            // 지정된 인터넷 IP 주소 및 포트에 연결할 수 있는 클라이언트 생성

void setup() {
  Serial.begin(115200);

  // We start by connecting to a WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(AP_ssid);

  WiFi.begin(AP_ssid, AP_password);            // WIFI 연결 시작

  while (WiFi.status() != WL_CONNECTED) {      // WIFI가 연결이 되어 있지 않다면
      delay(500);
      Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");

  if(client.connect(server, 80)) {             // 클라이언트가 연결됐다면
    Serial.println("server connected");
  }

  client.connect(server, port);                // 지정된 IP 주소와 포트에 연결
}

void loop() {
  if(client.available()){                      // 서버가 클라이언트에 쓴 데이터가 있는가?
    char c = client.read();                    // 서버에서 수신한 데이터 읽어오기
    Serial.println(c);
  }
  
}