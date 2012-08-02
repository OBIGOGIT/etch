/* $Id$
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements. See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to you under the Apache License, Version
 * 2.0 (the "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "transport/EtchPacketizer.h"
#include "common/EtchString.h"
#include "common/EtchError.h"
#include "util/EtchURL.h"
#include "transport/EtchTcpConnection.h"
#include "capu/util/SmartPointer.h"
#include "common/EtchSocket.h"
#include "transport/EtchSessionListener.h"
#include "transport/EtchTcpListener.h"
#include "transport/EtchSessionPacket.h"
#include "transport/EtchFlexBuffer.h"

class MockListener3 : public virtual EtchSessionListener<EtchSocket> {
public:

  //This method is called

  status_t sessionAccepted(EtchSocket* connection) {
    delete connection;
    return ETCH_OK;
  }

  MOCK_METHOD2(sessionQuery, status_t(capu::SmartPointer<EtchObject> query, capu::SmartPointer<EtchObject> &result));

  MOCK_METHOD2(sessionControl, status_t(capu::SmartPointer<EtchObject> control, capu::SmartPointer<EtchObject> value));

  status_t sessionNotify(capu::SmartPointer<EtchObject> event) {
    return ETCH_OK;
  }
};

class MockMessagizer : public EtchSessionPacket {
public:

  MOCK_METHOD2(sessionPacket, status_t(capu::SmartPointer<EtchWho> receipent, capu::SmartPointer<EtchFlexBuffer> buf));

  MOCK_METHOD2(sessionQuery, status_t(capu::SmartPointer<EtchObject> query, capu::SmartPointer<EtchObject> &result));

  MOCK_METHOD2(sessionControl, status_t(capu::SmartPointer<EtchObject> control, capu::SmartPointer<EtchObject> value));

  status_t sessionNotify(capu::SmartPointer<EtchObject> event) {
    return ETCH_OK;
  }
};

TEST(EtchPacketizer, constructorTest) {
  EtchURL u("tcp://127.0.0.1:4001");
  EtchTransportData* conn = new EtchTcpConnection(NULL, &u);
  EtchSessionData* packetizer = new EtchPacketizer(conn, &u);
  delete packetizer;
  delete conn;
}

TEST(EtchPacketizer, TransportControlTest) {
  EtchURL u("tcp://127.0.0.1:4001");
  EtchTransportData* conn = new EtchTcpConnection(NULL, &u);
  EtchPacketizer* res = new EtchPacketizer(conn, &u);
  MockMessagizer mes;
  res->setSession(&mes);
  EtchSessionListener<EtchSocket>* mSessionListener = new MockListener3();
  EtchTcpListener* listener = new EtchTcpListener(&u);
  //Start the mock listener
  listener->setSession(mSessionListener);
  listener->transportControl(new EtchString(EtchTcpListener::START_AND_WAIT_UP), new EtchInt32(1000));
  res->transportControl(new EtchString(EtchPacketizer::START_AND_WAIT_UP), new EtchInt32(1000));

  res->transportControl(new EtchString(EtchPacketizer::STOP_AND_WAIT_DOWN), new EtchInt32(1000));
  listener->transportControl(new EtchString(EtchTcpListener::STOP_AND_WAIT_DOWN), new EtchInt32(1000));

  conn->setSession(NULL);
  res->setSession(NULL);
  listener->setSession(NULL);

  delete mSessionListener;
  delete res;
  delete conn;
  delete listener;
}

TEST(EtchPacketizer, TransportPacketTest) {
  EtchURL u("tcp://127.0.0.1:4001");
  EtchTransportData* conn = new EtchTcpConnection(NULL, &u);
  EtchPacketizer* packetizer = new EtchPacketizer(conn, &u);
  MockMessagizer mes;
  packetizer->setSession(&mes);
  capu::SmartPointer<EtchFlexBuffer> buffer = new EtchFlexBuffer();

  //A packet is try to transmit data through not started transport
  buffer->put((capu::int8_t *)"_header_", packetizer->getHeaderSize());
  buffer->put((capu::int8_t *)"test", 4);
  buffer->setIndex(0);

  EXPECT_TRUE(packetizer->transportPacket(NULL, buffer) == ETCH_ERROR);

  delete packetizer;
  delete conn;
}

TEST(EtchPacketizer, SessionDataTest) {
  EtchURL u("tcp://127.0.0.1:4001");
  EtchTransportData* conn = new EtchTcpConnection(NULL, &u);
  EtchPacketizer* packetizer = new EtchPacketizer(conn, &u);
  capu::SmartPointer<EtchFlexBuffer> buffer = new EtchFlexBuffer();
  //A packet is created
  capu::int32_t pktsize = 4;
  buffer->put((capu::int8_t *) & packetizer->SIG, sizeof (capu::int32_t));
  buffer->put((capu::int8_t *) & pktsize, sizeof (capu::int32_t));
  buffer->put((capu::int8_t *)"test", pktsize);
  buffer->setIndex(0);
  EXPECT_TRUE(buffer->getLength() == 12);

  EtchSessionPacket* mSessionPacker = new MockMessagizer();
  packetizer->setSession(mSessionPacker);

  MockMessagizer * mock = (MockMessagizer*) mSessionPacker;
  EXPECT_CALL(*mock, sessionPacket(capu::SmartPointer<EtchWho > (NULL), buffer));
  EXPECT_TRUE(packetizer->sessionData(NULL, buffer) == ETCH_OK);

  packetizer->setSession(NULL);
  delete mSessionPacker;
  delete packetizer;
  delete conn;
}