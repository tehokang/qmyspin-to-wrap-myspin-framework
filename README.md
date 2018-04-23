
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







```python
from IPython.display import Image 
Image(url="https://github.com/tehokang/phoneprojection/blob/master/docs/figures/qmyspin-class-diagram.png", width=400,height=400)
```




<img src="https://github.com/tehokang/phoneprojection/blob/master/docs/figures/qmyspin-class-diagram.png" width="400" height="400"/>



Basically QmySPIN will be released as library type like files having so extension.

## 3. How QmySPIN builds
## 4. How QmySPIN runs
