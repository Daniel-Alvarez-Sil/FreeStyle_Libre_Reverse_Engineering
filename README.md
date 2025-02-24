<p align="center">
  <img src="https://github.com/user-attachments/assets/46574bea-4b6b-4661-a2f7-22916d3c597f" width="200" />
</p>

# FreeStyle Libre Reverse Engineering Project
Reverse Engineering Project to extract information from a FreeStyle Libre Sensor. 

Special thanks to the following repositories. Without their contribution this work would not be possible. If you are interested in increasing the functionality of your sensor, I highly recommend taking a deep dive into this repositories: 
- https://github.com/captainbeeheart/openfreestyle
- https://github.com/UPetersen/LibreMonitor
- https://github.com/humbertokramm/FreestyleSensorLibre

<p align="center">
  <img src="https://github.com/user-attachments/assets/54c2b5b6-9f64-4aea-990d-20d95de5dd38" width="100%" style="vertical-align: middle;" />
</p>

The general goal of this project is to expose the vulnerabilities present in the FreeStyle Libre device, specially those associated with NFC technology. For this project, we will be using the Hunter Cat NFC device built by Electronic Cats. Said device employs A PN7150 NFC controller, but virtually any NFC controller device that supports ISO15693 read/write operations can be used. 
- Hunter Cat NFC:
  - [**Buy**](https://electroniccats.com/store/hunter-cat-nfc/)
  - [**Official repository of Hunter Cat NFC**](https://github.com/ElectronicCats/HunterCatNFC)
- PN7150:
  - [**Repository by Electronic Cats**](https://github.com/ElectronicCats/ElectronicCats-PN7150)

Lastly, the Hunter Cat NFC is Arduino compatible. Thus, we will be using it to code the functionality to read the FreeStyle Libre. Next, we will use Python (a Jupyter Notebook) to make sense of the information read by the Hunter Cat. In general, the tools used in this project are employed as follows. 
<p align="center">
    <img src="https://github.com/user-attachments/assets/5c7abeeb-e387-4c23-817d-f41db368419e" width="550" style="vertical-align: middle;" />
</p>

## Documentation
### Glucose Readings
As of now, the reading of glucose information from the sensor (without credentials) is available within the **Glucose Readings** folder. There, you can find more detailed documentation regarding this functionality. 
   [**Glucose Readings Documentation**](https://github.com/Daniel-Alvarez-Sil/FreeStyle_Libre_Reverse_Engineering/blob/main/Glucose%20Readings/README.md)

### Sensor Rebirth
I am currently working on the rebirth of a FreeStyle Libre Sensor. This section will be available soon, if God wills. 
  [*Future Documentation of Sensor Revival*](https://github.com/Daniel-Alvarez-Sil/FreeStyle_Libre_Reverse_Engineering/blob/main/Sensor%20Rebirth/README.md)







