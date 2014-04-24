// This file automatically generated by:
//   Apache Etch 1.3.0-incubating (LOCAL-0) / c 1.3.0-incubating (LOCAL-0)
//   Fri Jul 27 11:35:36 CEST 2012
// This file is automatically created for your convenience and will not be
// overwritten once it exists! Please edit this file as necessary to implement
// your service logic.

#ifndef __HELLOWORLDCLIENT_H__
#define __HELLOWORLDCLIENT_H__

#include "BaseHelloWorldClient.h"
#include "HelloWorldHelper.h"

namespace org_apache_etch_examples_helloworld_HelloWorld {
  /**
   * Your custom implementation of BaseHelloWorldClient. Add methods here to provide
   * implementations of messages from the mServer.
   */
  class ImplHelloWorldClient : public BaseHelloWorldClient
  {
    /**
     * A connection to the mServer session. Use this to send a
     * message to the mServer.
     */
  private:
    RemoteHelloWorldServer* mServer;

  public:
    /**
     * Constructs the ImplHelloWorldClient.
     *
     * @param mServer a connection to the mServer session. Use this to send a
     * message to the mServer.
     */
    ImplHelloWorldClient( RemoteHelloWorldServer* mServer );
    virtual ~ImplHelloWorldClient() {}


    virtual status_t _sessionNotify(capu::SmartPointer<EtchObject> event );

    // TODO insert methods here to provide declarations of HelloWorldClient
    // messages from the mServer.
  };
}

#endif /* __HELLOWORLDCLIENT_H__ */