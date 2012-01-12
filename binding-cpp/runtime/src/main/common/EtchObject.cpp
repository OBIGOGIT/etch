/* $Id$
 *
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

#include "common/EtchObject.h"

EtchObject::EtchObject(capu::int32_t typeId){
  m_typeId = typeId;
}

capu::int32_t EtchObject::getObjectTypeId() const{
  return m_typeId;
}

EtchObject::~EtchObject(){
}

capu::uint64_t EtchObject::getHashCode(){
  return (capu::uint64_t) this;
}

capu::bool_t EtchObject::equals(const EtchObject* other){
  return (other == this);
}

