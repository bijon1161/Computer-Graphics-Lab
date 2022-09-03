/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.selective_repeat_sliding_window_protocol;

/**
 *
 * @author shakil
 */
import java.util.*;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;

public class sender1 {

    static ServerSocket Serversocket;
    static DataInputStream dis;
    static DataOutputStream dos;
    //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws SocketException {

        try {
            
            Scanner myObj = new Scanner(System.in);
            System.out.print("Enter no. of frames to be sent:");
            int count = myObj.nextInt();
            int a[]=new int[count];
            for(int i=0;i<count;i++){
               a[i] = myObj.nextInt();
            }
           // int a[] = {30, 40, 50, 60, 70, 80, 90, 100};
            Serversocket = new ServerSocket(8011);
            System.out.println("waiting for connection");
            Socket client = Serversocket.accept();
            dis = new DataInputStream(client.getInputStream());
            dos = new DataOutputStream(client.getOutputStream());
            System.out.println("The number of packets sent is:" + a.length);
            int y = a.length;
            dos.write(y);
            dos.flush();

            for (int i = 0; i < a.length; i++) {
                dos.write(a[i]);
                dos.flush();
            }

            int k = dis.read();

            dos.write(a[k]);
            dos.flush();

        } catch (IOException e) {
            System.out.println(e);
        } finally {
            try {
                dis.close();
                dos.close();
            } catch (IOException e) {
                e.printStackTrace();
            }

        }
    }
}
