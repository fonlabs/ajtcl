/*
 * interface-management.c
 *
 *  Created on: Oct 22, 2014
 *      Author: javier
 */

#include <alljoyn.h>

int main(int argc, char **argv)
{
    AJ_InterfaceDescription *data, **array;
    char ***iter;
    int x, y;

    array = AJ_InterfacesCreate();

    data = AJ_InterfaceDescriptionCreate("org.alljoyn.Bus.sample");
    if (!data)
        return 1;
    AJ_InterfaceDescriptionAdd(data, "?Dummy foo<i");
    AJ_InterfaceDescriptionAdd(data, "?Dummy2 fee<i");
    AJ_InterfaceDescriptionAdd(data, "?cat inStr1<s inStr2<s outStr>s");
    AJ_InterfacesAdd(array, data);

    data = AJ_InterfaceDescriptionCreate("org.alljoyn.Bus");
    if (!data)
        return 1;
    AJ_InterfaceDescriptionAdd(data, "!SessionLost >u");
    AJ_InterfaceDescriptionAdd(data, "!FoundAdvertisedName >s >q >s");
    AJ_InterfaceDescriptionAdd(data, "!LostAdvertisedName >s >q >s");
    AJ_InterfaceDescriptionAdd(data, "!MPSessionChanged >u >s >b");
    AJ_InterfaceDescriptionAdd(data, "?AdvertiseName <s <q >u");
    AJ_InterfaceDescriptionAdd(data, "?CancelAdvertiseName <s <q >u");
    AJ_InterfaceDescriptionAdd(data, "?FindAdvertisedName <s >u");
    AJ_InterfaceDescriptionAdd(data, "?CancelFindAdvertisedName <s");
    AJ_InterfaceDescriptionAdd(data, "?BindSessionPort <q <a{sv} >u >q");
    AJ_InterfaceDescriptionAdd(data, "?UnbindSessionPort <q >u");
    AJ_InterfaceDescriptionAdd(data, "?JoinSession <s <q <a{sv} >u >u >a{sv}");
    AJ_InterfaceDescriptionAdd(data, "?LeaveSession <u >u");
    AJ_InterfaceDescriptionAdd(data, "?CancelSessionlessMessage <u >u");
    AJ_InterfaceDescriptionAdd(data, "?FindAdvertisedNameByTransport <s <q >u");
    AJ_InterfaceDescriptionAdd(data, "?CancelFindAdvertisedNameByTransport <s <q >u");
    AJ_InterfaceDescriptionAdd(data, "?SetLinkTimeout <u <u >u >u");
    AJ_InterfaceDescriptionAdd(data, "?RemoveSessionMember <us >u");
    AJ_InterfaceDescriptionAdd(data, "!SessionLostWithReason >u >u");
    AJ_InterfaceDescriptionAdd(data, "?Ping <s <u >u");
    AJ_InterfacesAdd(array, data);

    data = AJ_InterfaceDescriptionCreate("org.freedesktop.DBus");
    AJ_InterfaceDescriptionAdd(data, "?Hello >s");
    AJ_InterfaceDescriptionAdd(data, "!NameOwnerChanged >s >s >s");
    AJ_InterfaceDescriptionAdd(data, "!NameAcquired >s");
    AJ_InterfaceDescriptionAdd(data, "!NameLost >s");
    AJ_InterfaceDescriptionAdd(data, "!PropertiesChanged >s >a{sv} >as");
    AJ_InterfaceDescriptionAdd(data, "?RequestName <s <u >u");
    AJ_InterfaceDescriptionAdd(data, "?AddMatch <s");
    AJ_InterfaceDescriptionAdd(data, "?RemoveMatch <s");
    AJ_InterfaceDescriptionAdd(data, "?ReleaseName <s >u");
    AJ_InterfacesAdd(array, data);

    data = AJ_InterfaceDescriptionCreate("#org.freedesktop.DBus.Properties");
    AJ_InterfaceDescriptionAdd(data, "?Get <s <s >v");
    AJ_InterfaceDescriptionAdd(data, "?Set <s <s <v");
    AJ_InterfaceDescriptionAdd(data, "?GetAll <s >a{sv}");
    AJ_InterfacesAdd(array, data);

    data = AJ_InterfaceDescriptionCreate("org.alljoyn.Daemon");
    AJ_InterfaceDescriptionAdd(data, "!ProbeReq");
    AJ_InterfaceDescriptionAdd(data, "!ProbeAck");
    AJ_InterfacesAdd(array, data);

    for (iter = (char ***) array, x = 0; array && iter[x]; x++) {
        for (y = 0; iter[x][y]; y++) {
            if(y)
                printf("\t");
            printf("%s\n", iter[x][y]);
        }

    }

    AJ_InterfacesDelete(array);

    printf("Deleting stuff\n");

    for (iter = (char ***) array, x = 0; array && iter[x]; x++) {
        for (y = 0; iter[x][y]; y++) {
            if(y)
                printf("\t");
            printf("%s\n", iter[x][y]);
        }
    }

    return 0;
}
