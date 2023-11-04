# wifi-jammer

이 코드는 ESP8266를 사용하여 사용 가능한 WiFi 네트워크를 스캔하고, 발견된 첫 번째 네트워크의 BSSID(액세스 포인트의 고유 MAC 주소) 및 채널을 가져온 후 해당 BSSID로 Deauthentication 패킷을 전송합니다. 이러한 작업은 네트워크에서 디바이스를 강제로 로그아웃시킬 수 있습니다.

## 사용법

### 1. ESP8266 개발 환경을 설정합니다.

### 2. 코드를 ESP8266 보드에 업로드합니다.

### 3. 진행 과정을 확인하기 위해 시리얼 모니터를 엽니다.

## 주의 사항

-   이 코드의 부적절한 사용은 법과 윤리를 위반할 수 있습니다.
-   이 스크립트는 보안 테스트 및 학습 목적으로만 사용해야 합니다.
-   다른 사람의 무선 네트워크를 공격하는 것은 불법이며, 사용 권한이 있는 네트워크에서만 테스트해야 합니다.

## 참고 링크

-   [ESP8266 Injection Example](https://github.com/pulkin/esp8266-injection-example/)
-   [ESP8266 Deauther by SpacehuhnTech](https://github.com/SpacehuhnTech/esp8266_deauther)
