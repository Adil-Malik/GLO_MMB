#Inspried by Arduino RSS Instructable
import string
#http library
import urllib2
#Serial Library
import serial
#Time Library
import time
#import xml parser called minidom:
from xml.dom.minidom import parseString
#Add the correct Serial port of you arduino here
#ser = serial.Serial("\\.\COM5", 9600)
i = 1
j = 2
#delay for stability while connection is achieved
time.sleep(5)
while i == 1:
     #Add your RSS link here
     file = urllib2.urlopen('http://feeds.bbci.co.uk/news/science_and_environment/rss.xml?edition=uk')
     data = file.read()
     file.close()
     #parse the xml from the string
     dom = parseString(data)
     #retrieve the first xml tag (<tag>data</tag>) that the parser finds with name tagName change tags to get different data
     xmlTag = dom.getElementsByTagName('title')[j].toxml()
     # Send different RSS Titles
     #strip off the tag (<tag>data</tag>  --->   data)
     xmlData=xmlTag.replace('<title>','').replace('</title>','')
     #upper Case everything
     xmlData = str(xmlData).upper()
     #Print to screen
     print xmlData
     #Write the whole string to the Arduino, with 3 spaces so in the end the String doesnt block the message.
     #ser.write ("   ", xmlData)
     #Go through different Titles in the RSS Feed
     j = j + 1
     #This is the refresh time between messages in seconds.
     time.sleep(300)
     
     
