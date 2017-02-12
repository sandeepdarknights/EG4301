from pyonep import onep
#import datetime

def dataCapture():
    o = onep.OnepV1()
    cik = '22781660f6fa7fbfe773057dfa4e93cb83e85869'
    dataport_alias = 'temp'
    #val_to_write = '1'
    # https://github.com/exosite/docs/tree/master/rpc#write
    #o.write(
    #    cik,
    #    {"alias": dataport_alias},
    #    val_to_write,
    #    {})
    # https://github.com/exosite/docs/tree/master/rpc#read
    isok, responses = o.read(
        cik,
        {'alias': dataport_alias},
        {'limit': 10, 'sort': 'desc', 'selection': 'all'})
    #if isok:
        # expect Read back [[1374522992, 1]]
        #print("%s" % response)
        #print response
        #for response in responses:
            #time=datetime.datetime.fromtimestamp(int(response[0])).strftime('%Y-%m-%d %H:%M:%S')
            #print "patient has a temperature of " + str(response[1]) + " at " + time
    #else:
        #print("Read failed: %s" % response)
    return responses
