#!/usr/bin/python2
from __future__ import print_function

__author__ = 'javier'

import alljoyn

service_name = 'org.alljoyn.Bus.sample'
service_path = '/sample'
service_port = 25

sample_interfaces = alljoyn.AJ_InterfacesCreate()

sample_interface = alljoyn.AJ_InterfaceDescriptionCreate(
    'org.alljoyn.Bus.sample')
sample_interface = alljoyn.AJ_InterfaceDescriptionAdd(sample_interface,
                                                      '?Dummy foo<i')
sample_interface = alljoyn.AJ_InterfaceDescriptionAdd(sample_interface,
                                                      '?Dummy2 fee<i')
sample_interface = alljoyn.AJ_InterfaceDescriptionAdd(sample_interface,
                                                      '?cat inStr1<s inStr2<s outStr>s')
sample_interfaces = alljoyn.AJ_InterfacesAdd(sample_interfaces,
                                             sample_interface)

obj = alljoyn.AJ_Object()
obj.path = service_path
obj.interfaces = sample_interfaces

print(obj)

app_objects = obj

alljoyn.AJ_Initialize()
alljoyn.AJ_PrintXML(app_objects)
bus = alljoyn.AJ_BusAttachment()
sessionid = alljoyn.AJ_StartClient(bus,
                                   None,
                                   60 * 1000,
                                   alljoyn.FALSE,
                                   service_name,
                                   service_port,
                                   None)
