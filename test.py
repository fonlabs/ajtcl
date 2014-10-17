#!/usr/bin/python2
__author__ = 'javier'

import alljoyn

service_name = 'org.alljoyn.Bus.sample'
service_path = '/sample'
service_port = 25
sample_interface = (
    'org.alljoyn.Bus.sample',
    '?Dummy foo<i',
    '?Dummy2 fee<i',
    '?cat inStr1<s inStr2<s outStr>s',
    None
)

sample_interfaces = sample_interface

obj = alljoyn.AJ_Object()
obj.path = service_path
obj.interfaces = sample_interfaces

app_objects = [obj]

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
