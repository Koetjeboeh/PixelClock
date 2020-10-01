#ifndef __HTTP_UPDATE_SERVER_H
#define __HTTP_UPDATE_SERVER_H

class ESP8266WebServer;

static const String emptyString = "";
static const String emptyString1 = "";

class ESP8266HTTPUpdateServer
{
  public:
    ESP8266HTTPUpdateServer(bool serial_debug=false,int command=U_FLASH);

    void setup(ESP8266WebServer *server)
    {
      setup(server, emptyString1, emptyString1);
    }

    void setup(ESP8266WebServer *server, const String& path)
    {
      setup(server, path, emptyString1, emptyString1);
    }

    void setup(ESP8266WebServer *server, const String& username, const String& password)
    {
      setup(server, "/update", username, password);
    }

    void setup(ESP8266WebServer *server, const String& path, const String& username, const String& password);

    void updateCredentials(const String& username, const String& password)
    {
      _username = username;
      _password = password;
    }

  protected:
    void _setUpdaterError();

  private:
    bool _serial_output;
    ESP8266WebServer *_server;
    String _username;
    String _password;
    bool _authenticated;
    String _updaterError;
    int _command;
};


#endif
