a
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
* <a href="https://www.youtube.com/watch?v=Xm8vdCJfDZs"> infoware.de Review mySPIN </a> (recommended)

If you get understanding original mySPIN then let's get more thing to understand QmySPIN. <br>
Originally our framework supporting to mySPIN is made for covering all of multiscreen framework like mySPIN, SDL, Abalta and more things.<br>


### 2.2 Understanding QmySPIN from Humax

#### 2.2.1 Architecture


Following is the architecture of QmySPIN including myspin and more.

<center>
<img src="https://github.com/tehokang/public-figures/blob/master/qmyspin/qmyspin-architecture.png?raw=true"/>
</center>

The diagram consist of main three block, User, SDK and Platform. 
* User : Normally user will make their own application, e.g. HMI(Human Machin Interface) Application like head unit application. The application will use QmySPIN wrapper class.
* SDK : The core of SDK will consist of libraries, 
> transport-adapter : released by Humax to control devices like USB, Bluetooth, TCP to connect/disconnect/send/receive <br>
> projection-handler : released by Humax to control 3rdparty like mySPIN, Abalta, SDL and so on.<br>
> mySPIN library : released by Bosch-SoftTec to control mySPIN core <br>
* Platform : System libraries are deployed which QmySPIN can use, like libusb.so, libbluetooth.so, libsocket.so and so on. Our SDK will use these resource from Platform.<br>


#### 2.2.2 Relations

<center><img src="https://github.com/tehokang/public-figures/blob/master/qmyspin/QmySPIN-relation-flow.png?raw=true"/> QmySPIN-relation-diagram </center>

I will use this relation diagram to represent the flow when working. <br>
It will help you to understand easily the each steps from connecting to communicating like sending, receiving and disconnecting. <br>
Where is Phone-Projection Coordinator? That's right, it will be merged into QmySPIN. <br>
Phone-Projection Coordinator just mean abstract layer. Let's see how they are working. <br>

##### 2.2.2.1 Initialize

<center><img src="https://github.com/tehokang/public-figures/blob/master/qmyspin/QmySPIN-relation-flow-initialize.png?raw=true"/> Fig. Initializing QmySPIN </center>

QmySPIN will be initialized by User creating QmySPIN::createInstance() and calling init(). Then QmySPIN will initialize internal resources like ProjectionHandler and TransportAdapter.
* ProjectionHandler : This is to control 3rdparty PhoneProjection framework
* TransportAdapter : This is to control USB, Bluetooth, TCP devices which can be connected to head unit.

(The red colored-number means the sequence of calling order)

##### 2.2.2.2 Scan

<center><img src="https://github.com/tehokang/public-figures/blob/master/qmyspin/QmySPIN-relation-flow-scan.png?raw=true"/> Fig. Scanning </center>

##### 2.2.2.3 Connect

<center><img src="https://github.com/tehokang/public-figures/blob/master/qmyspin/QmySPIN-relation-flow-connect.png?raw=true"/> Fig. Connecting </center>

##### 2.2.2.4 Attached event and connect

<center><img src="https://github.com/tehokang/public-figures/blob/master/qmyspin/QmySPIN-relation-flow-attached-event.png?raw=true"/> Fig. Attached Event and Connecting </center>

##### 2.2.2.5 Dettached event and disconnect

<center><img src="https://github.com/tehokang/public-figures/blob/master/qmyspin/QmySPIN-relation-flow-dettached-event.png?raw=true"/> Fig. Dettached Event and Disconnecting </center>

## 3. How QmySPIN builds

### 3.1 Build Tree

You can download sources via Subversion [here](http://svn.humaxdigital.com/browser/home/thkang2/qmyspin/) as temporary.

The modules you saw right before are in src directory of following, 
As you can see, 3rdparty is having libraries so that src can use 3rdparty phoneprojection framework as library and system library like libusb.

<pre>
.
├── 3rdparty
│   ├── libusb
│   │   └── 1.0
│   │       ├── pi3
│   │       ├── tcc
│   │       └── x86
│   └── myspin
│       └── 1.2.3
│           ├── arm
│           └── tcc
├── cmake
├── docs
│   └── figures
└── src
    ├── examples
    │   └── myspin : HMI Example Application, Not perfect ;)
    ├── export
    │   ├── include
    │   └── src
    ├── projection-handler
    │   ├── abalta
    │   ├── cinemo
    │   ├── myspin
    │   └── sdl
    ├── transport-adapter
    │   ├── bluetooth
    │   ├── tcp
    │   └── usb
    └── utility
</pre>

### 3.2 How to build

QmySPIN for various platform toolchain(Raspberry pi3, Linux and so on) is prepared and you can see the configurations of each toolchain cmake directory like following BTW sometimes you should modify them if you meet compile error.
* cross-general-arm-gcc-4.8.1.cmake
* cross-brcm-arm-gcc-4.8.1.cmake
* cross-tcc-arm-gcc-4.8.1.cmake

Please following below scripts to build for Raspberry Pi3
> mkdir build <br>
> cd build <br>
> cmake ../ -DCMAKE_TOOLCHAIN_FILE=../cmake/cross-general-arm-gcc-4.8.1.cmake <br>
> make <br>

After building, there are output files in build/out directory
* example-myspin : HMI User Example applicaiton 
* libproject-export.so : QmySPIN wrapper library
* libprojection-handler.so : 3rdparty phone projection wrapper library
* libtransport-adapter.so : TransportAdapter library
* libutility.so : Utilities QmySPIN using

To execute example-myspin you need 3rdparty phone projections's core libraries, <br>
For instance, case of myspin you need libmySPIN-Core.so and you can look for them via 3rdparty directory.




## 4. How QmySPIN runs

You can run the example executable like following, <br>
> cd build/out <br>
> sudo ./example-myspin <br>

Probably you can't run it since you didn't set library path of mySPIN's core library.
Please do setting like LD_LIBRARY_PATH, for instance,
> LD_LIBRARY_PATH=../3rdparty/myspin/1.2.3/arm/32bit/debug/lib/ ./out/example-myspin

Then finally you will meet menu on console
>######################## <br>
> s : scan usb devices <br>
> c : connect <br>
> d : disconnect <br>
> x : exit <br>
> 1 : send home key <br>
> 2 : send menu key <br>
> 3 : send back key <br>
> 4 : send search key <br>
> ? : show menu <br>
>######################## <br>
>input : <br>

Sometimes you need root right to do that. I couldn't listen event of USB on my MacBook Pro.
After executing, please attach your Android phone via USB-cable then you can see logging example-myspin can receive data can represent from your phone.
