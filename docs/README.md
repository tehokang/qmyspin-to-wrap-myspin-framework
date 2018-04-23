
# QmySPIN Tutorial
## 1 .What QmySPIN is

QmySPIN is a component-wrapper class to use mySPIN framework of Bosch SoftTec in Qt or any environment like Raspberry pi, windows or Linux.<br>
Basically mySPIN is a framework in car-infortainment especially they called as multiscreen of technologies, it made by German company Bosch-SoftTec <br>
The detail document of mySPIN is <a href="http://www.bosch-softtec.com/myspin.html"> here </a> released by Bosch SoftTec.

## 2. How QmySPIN works

### 2.1 Understanding orinary mySPIN
Conceptually QmySPIN) will be deploy in head unit(=HU) then it's working with smart phone already having mySPIN application. <br>
The kinds of mobile application are Android and Apple version. Each type of application owns their protocol.<br>
In case of Android, it requires AOAP(=Android Open Accessory Protocol) to start communication between HU and Android. <br>
After done AOAP, each terminal can communicate via general USB communication. mySPIN is communicate for HU's rendering. <br>
In case of Apple, it requires IAP(or IAP2), EAP to start communication between HE and Apple. Next step is same with Android
s'.<br>
First of all to understand How QmySPIN works, you need to watch introduction of mySPIN from Bosch-SoftTec of following. <br>

* <a href="https://www.youtube.com/watch?v=W-oRnY5G5WQ"> EICMA2016 Demo mySPIN </a>
* <a href="https://www.youtube.com/watch?v=Xm8vdCJfDZs"> infoware.de Review mySPIN </a>

If you get understanding original mySPIN then let's get more thing to understand QmySPIN. <br>
Originally our framework supporting to mySPIN is made for covering all of multiscreen framework like mySPIN, SDL, Abalta and more things.<br>


### 2.2 Understanding QmySPIN from Humax

#### 2.2.1 Architecture


Following is the architecture of QmySPIN including myspin and more.

<img src="https://github.com/tehokang/phoneprojection/blob/master/docs/figures/qmyspin-architecture.png"> QmySPIN-Architecture </img>

The diagram consist of main three block, User, SDK and Platform. 
* User : Normally user will make their own application, e.g. HMI(Human Machin Interface) Application like head unit application. The application will use QmySPIN wrapper class.
* SDK : The core of SDK will consist of libraries, 
> mySPIN library : released by Bosch-SoftTec to control mySPIN core <br>
> transport-adapter : released by Humax to control devices like USB, Bluetooth, TCP to connect/disconnect/send/receive 
* Platform : System libraries are deployed which QmySPIN can use, like libusb.so, libbluetooth.so, libsocket.so and so on. Our SDK will use these resource from Platform.<br>


<img src="https://github.com/tehokang/phoneprojection/blob/master/docs/figures/qmyspin-relation-diagram.png"> QmySPIN-relation-diagram</img>

This is relation diagram to represent the flow when working. It will help you to understand easily the each steps from connecting to communicating like sending, receiving and disconnecting. As you can see, HMI User application should use libraries of QmySPIN, 

## 3. How QmySPIN builds

## 4. How QmySPIN runs
