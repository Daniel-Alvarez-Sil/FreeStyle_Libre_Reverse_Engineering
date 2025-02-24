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
  - Buy: https://electroniccats.com/store/hunter-cat-nfc/
  - Repository: https://github.com/ElectronicCats/HunterCatNFC
- PN7150:
  - Repository by Electronic Cats: https://github.com/ElectronicCats/ElectronicCats-PN7150

Lastly, the Hunter Cat NFC is Arduino compatible. Thus, we will be using it to code the functionality to read the FreeStyle Libre. Next, we will use Python (a Jupyter Notebook) to make sense of the information read from the Hunter Cat. In general, the tools used in this project are employed as follows. 
<p align="center">
    <img src="https://github.com/user-attachments/assets/5c7abeeb-e387-4c23-817d-f41db368419e" width="550" style="vertical-align: middle;" />
</p>






