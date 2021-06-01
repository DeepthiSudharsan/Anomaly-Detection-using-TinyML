### Anomaly Detection (w/ Network Detection dataset) using tinyML

#### Dataset Source: https://www.kaggle.com/anushonkar/network-anamoly-detection?select=Train.txt

#### In this project we will be classifying the Network data as normal (encoded as label 1) or attack (encoded as label 0) by training a tensorflow model, and then loading the model in a microcontroller and observing the accuracy of classification in the serial monitor. 

****
### A glimpse of the dataset

**duration**|**protocoltype**|**service**|**flag**|**srcbytes**|**dstbytes**|**land**|**wrongfragment**|**urgent**|**hot**|**numfailedlogins**|**loggedin**|**numcompromised**|**rootshell**|**suattempted**|**numroot**|**numfilecreations**|**numshells**|**numaccessfiles**|**numoutboundcmds**|**ishostlogin**|**isguestlogin**|**count**|**srvcount**|**serrorrate**|**srvserrorrate**|**rerrorrate**|**srvrerrorrate**|**samesrvrate**|**diffsrvrate**|**srvdiffhostrate**|**dsthostcount**|**dsthostsrvcount**|**dsthostsamesrvrate**|**dsthostdiffsrvrate**|**dsthostsamesrcportrate**|**dsthostsrvdiffhostrate**|**dsthostserrorrate**|**dsthostsrvserrorrate**|**dsthostrerrorrate**|**dsthostsrvrerrorrate**|**attack**|**lastflag**
:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:
0|tcp|ftp_data|SF|491|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|2|2|0|0|0|0|1|0|0|150|25|0.17|0.03|0.17|0|0|0|0.05|0|normal|20
0|udp|other|SF|146|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|13|1|0|0|0|0|0.08|0.15|0|255|1|0|0.6|0.88|0|0|0|0|0|normal|15
