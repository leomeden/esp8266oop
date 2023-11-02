#include <WifiConexion.h>



WifiConexion::WifiConexion(const char* ssid, const char* pass)
{
    const char* _ssid = ssid;
    const char* _pass = pass;
    WiFi.begin(_ssid, _pass);

};

bool WifiConexion::conectar()
{
    
  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }
  return true;

};