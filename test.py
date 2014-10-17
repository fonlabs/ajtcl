#!/usr/bin/python2
__author__ = 'javier'

import alljoyn

service_name = 'org.alljoyn.Bus.sample'
service_path = '/sample'
service_port = 25
sample_interface = ['org.alljoyn.Bus.sample', '?Dummy foo<i', '?Dummy2 fee<i',
                    '?cat inStr1<s inStr2<s outStr>s']
sample_interfaces = [sample_interface]
app_objects = [(service_path, sample_interfaces)]

alljoyn.AJ_Initialize()
bus = alljoyn.AJ_BusAttachment()
sessionid = alljoyn.AJ_StartClient(bus,
                                   None,
                                   60 * 1000,
                                   alljoyn.FALSE,
                                   service_name,
                                   service_port,
                                   None)
