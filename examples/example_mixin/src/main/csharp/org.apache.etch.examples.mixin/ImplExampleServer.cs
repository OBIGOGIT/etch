// This file automatically generated by:
//   Apache Etch 1.2.0-incubating (LOCAL-0) / csharp 1.2.0-incubating (LOCAL-0)
//   Mon Mar 28 12:14:36 CEST 2011
// This file is automatically created for your convenience and will not be
// overwritten once it exists! Please edit this file as necessary to implement
// your service logic.

using System;


using org.apache.etch.examples.mixin.types.ExampleMixin;

using org.apache.etch.examples.mixin.types.Example;

///<summary>Your custom implementation of BaseExampleServer. Add methods here to provide
///implementation of messages from the client. </summary>
namespace org.apache.etch.examples.mixin
{
	///<summary>Implementation for ImplExampleServer</summary>
	public class ImplExampleServer : BaseExampleServer
	{
		/// <summary>Constructs the ImplExampleServer.</summary>
 		/// <param name="client">a connection to the client session. Use this to
 		/// send a message to the client.</param>
		public ImplExampleServer(RemoteExampleClient client)
		{
			this.client = client;
		}
		
		/// <summary>A connection to the client session. Use this to
 		/// send a message to the client.</summary>
		private readonly RemoteExampleClient client;

		public override string say_hello (string who)
		{
			return "Server: " + who;
		}
		
		public override string say_hello_mixin(string who)
		{
			return "Server-Mixin: " + who;
		}
}
}