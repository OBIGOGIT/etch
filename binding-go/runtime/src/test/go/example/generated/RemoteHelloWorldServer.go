/* 
  Licensed to the Apache Software Foundation (ASF) under one
  or more contributor license agreements. See the NOTICE file
  distributed with this work for additional information
  regarding copyright ownership. The ASF licenses this file
  to you under the Apache License, Version 2.0 (the
  "License"); you may not use this file except in compliance
  with the License. You may obtain a copy of the License at
  
    http://www.apache.org/licenses/LICENSE-2.0
  
  Unless required by applicable law or agreed to in writing,
  software distributed under the License is distributed on an
  "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
  KIND, either express or implied. See the License for the
  specific language governing permissions and limitations
  under the License.
*/ 
// This file automatically generated by:
//   Apache Etch 1.1.0-incubating (LOCAL-0) / go 1.1.0-incubating (LOCAL-0)
//   Thu Nov 18 15:39:28 CET 2010
// This file is automatically created and should not be edited!

package org_apache_etch_examples_helloworld

import "etch"

type RemoteHelloWorldServer struct {
     RemoteHelloWorld
     
     vf   etch.ValueFactory
     Dsvc etch.DeliveryService
}

func NewRemoteHelloWorldServer(dsvc etch.DeliveryService, vf etch.ValueFactory ) *RemoteHelloWorldServer {
     ret := &RemoteHelloWorldServer{}
     ret.Dsvc = dsvc
     ret.vf = vf
     return ret
}

func (remote *RemoteHelloWorldServer) TransportControl(ctrl interface{}, value interface{}) {
     remote.Dsvc.TransportControl(ctrl, value)
}


func (r *RemoteHelloWorldServer) Say_hello ( to_whom *User) string {
	msg := etch.NewMessage(r.vf.GetTypeByName("org.apache.etch.examples.helloworld.HelloWorld.say_hello"), r.vf, 1)
	if to_whom != nil {
		msg.Put(r.vf.(*ValueFactoryHelloWorld)._mf_to_whom, to_whom)
    	}

	retVal := r.Dsvc.EndCall(r.Dsvc.BeginCall(msg), r.vf.GetTypeByName("org.apache.etch.examples.helloworld.HelloWorld._result_say_hello"))
	return retVal.(string)
}
func (r *RemoteHelloWorldServer) Oneway ()  {
	msg := etch.NewMessage(r.vf.GetTypeByName("org.apache.etch.examples.helloworld.HelloWorld.oneway"), r.vf, 1)
	r.Dsvc.TransportMessage(nil, msg)
}
func (r *RemoteHelloWorldServer) Twoway ()  {
	msg := etch.NewMessage(r.vf.GetTypeByName("org.apache.etch.examples.helloworld.HelloWorld.twoway"), r.vf, 1)

	r.Dsvc.EndCall(r.Dsvc.BeginCall(msg), r.vf.GetTypeByName("org.apache.etch.examples.helloworld.HelloWorld._result_twoway"))
}
func (r *RemoteHelloWorldServer) SimpleArrayTest ( ints []int32)  {
	msg := etch.NewMessage(r.vf.GetTypeByName("org.apache.etch.examples.helloworld.HelloWorld.simpleArrayTest"), r.vf, 1)
		msg.Put(r.vf.(*ValueFactoryHelloWorld)._mf_ints, ints)

	r.Dsvc.EndCall(r.Dsvc.BeginCall(msg), r.vf.GetTypeByName("org.apache.etch.examples.helloworld.HelloWorld._result_simpleArrayTest"))
}
func (r *RemoteHelloWorldServer) StructArrayTest ( users []*User)  {
	msg := etch.NewMessage(r.vf.GetTypeByName("org.apache.etch.examples.helloworld.HelloWorld.structArrayTest"), r.vf, 1)
		msg.Put(r.vf.(*ValueFactoryHelloWorld)._mf_users, users)

	r.Dsvc.EndCall(r.Dsvc.BeginCall(msg), r.vf.GetTypeByName("org.apache.etch.examples.helloworld.HelloWorld._result_structArrayTest"))
}


