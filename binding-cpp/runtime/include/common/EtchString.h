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

#ifndef __ETCHSTRING_H__
#define __ETCHSTRING_H__

#include "common/EtchObject.h"
#include "util/EtchUtil.h"

/**
 * String type.
 */
class EtchString :
public EtchObject {

public:

  /**
   * TypeId for EtchString.
   */
  static const capu::int32_t TYPE_ID = EOTID_STRING;

  /**
   * Constructs the String.
   */
  EtchString();

  /**
   * Copy constructor
   * @param copy
   */
  EtchString(const EtchString & copy);

  /**
   * Constructs the String.
   * @param string as c string
   */
  EtchString(const char* string);

  /**
   * Destructure.
   */
  virtual ~EtchString();

  /**
   * Set a new string.
   * @param string as c string
   */
  void set(const char* string);

  /**
   * Set a new string.
   * @param string as c string
   * @param len as unsigned integer to represent size of string
   */
  void set(const char* string, capu::uint32_t len);

  /**
   * Returns the amount of characters in the string.
   * @return amount of characters
   */
  capu::int32_t length() const;

  /**
   * the substring is generated.
   * note: User must explicitly deallocate the returned object
   * @param start starting index of substring
   * @param length length of given string
   * @param dest where the substring will be stored
   * @return ETCH_OK if the substring has been successfully stored into the dest
   *         ETCH_EINVAL if there are errors in the indexing or buffer is NULL
   */
  status_t substring(capu::uint32_t start, capu::uint32_t length, EtchString *dest);

  /**
   * Returns the index of the first occurrence of a character within given string
   * @param c
   * @return index index of first occurrence of character
   *         -1 if the character is not found
   */
  capu::int32_t leftFind(const char c);

  /**
   * Returns the index of last occurrence of a character within given string
   * @param c
   * @return index index of last occurrence of character
   *         -1 if the character is not found
   */
  capu::int32_t rightFind(const char c);

  /**
   * Check two string is equal or not
   * @param other
   * @return true if this equals b, false otherwise. takes into account nulls.
   */
  capu::bool_t equals(const EtchObject * other) const;

  /**
   * Returns c styled string.
   */
  const char* c_str() const;

  /**
   * Returns c styled string.
   */
  const char* c_str();

  /**
   * Assignment operator overloading
   */
  EtchString& operator=(const EtchString &str);

  /**
   * Assignment operator overloading
   */
  EtchString& operator=(const EtchString *str);

  /**
   * Assignment operator overloading
   */
  EtchString& operator=(const char *str);

  /**
   * Returns hash code
   */
  capu::uint64_t getHashCode() const;

private:

  char* mData;
};

#endif
