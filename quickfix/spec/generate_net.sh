#!/bin/bash
set -e

xsltproc -o ../src/.NET/FIX40_MessageCracker.cs net_MessageCracker.xsl FIX40.xml
xsltproc -o ../src/.NET/FIX41_MessageCracker.cs net_MessageCracker.xsl FIX41.xml
xsltproc -o ../src/.NET/FIX42_MessageCracker.cs net_MessageCracker.xsl FIX42.xml
xsltproc -o ../src/.NET/FIX43_MessageCracker.cs net_MessageCracker.xsl FIX43.xml
xsltproc -o ../src/.NET/FIX44_MessageCracker.cs net_MessageCracker.xsl FIX44.xml
xsltproc -o ../src/.NET/FIX50_MessageCracker.cs net_MessageCracker.xsl FIX50.xml
xsltproc -o ../src/.NET/FIX50SP1_MessageCracker.cs net_MessageCracker.xsl FIX50SP1.xml
xsltproc -o ../src/.NET/FIX50SP2_MessageCracker.cs net_MessageCracker.xsl FIX50SP2.xml
xsltproc -o ../src/.NET/FIXT11_MessageCracker.cs net_MessageCracker.xsl FIXT11.xml

xsltproc -o ../src/.NET/FIX40_MessageFactory.cs net_MessageFactory.xsl FIX40.xml
xsltproc -o ../src/.NET/FIX41_MessageFactory.cs net_MessageFactory.xsl FIX41.xml
xsltproc -o ../src/.NET/FIX42_MessageFactory.cs net_MessageFactory.xsl FIX42.xml
xsltproc -o ../src/.NET/FIX43_MessageFactory.cs net_MessageFactory.xsl FIX43.xml
xsltproc -o ../src/.NET/FIX44_MessageFactory.cs net_MessageFactory.xsl FIX44.xml
xsltproc -o ../src/.NET/FIX50_MessageFactory.cs net_MessageFactory.xsl FIX50.xml
xsltproc -o ../src/.NET/FIX50SP1_MessageFactory.cs net_MessageFactory.xsl FIX50SP1.xml
xsltproc -o ../src/.NET/FIX50SP2_MessageFactory.cs net_MessageFactory.xsl FIX50SP2.xml
xsltproc -o ../src/.NET/FIXT11_MessageFactory.cs net_MessageFactory.xsl FIXT11.xml

