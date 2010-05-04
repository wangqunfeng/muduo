// Copyright 2010, Shuo Chen.  All rights reserved.
// http://code.google.com/p/muduo/
//
// Use of this source code is governed by a BSD-style license
// that can be found in the License file.

// Author: Shuo Chen (chenshuo at chenshuo dot com)
//

#include <muduo/net/http/HttpResponse.h>
#include <muduo/net/Buffer.h>

#include <stdio.h>

using namespace muduo;
using namespace muduo::net;

void HttpResponse::appendToBuffer(Buffer* output) const
{
  char buf[32];
  snprintf(buf, sizeof buf, "HTTP/1.1 %d ", statusCode_);
  string statusLine(buf);
  output->append(statusLine);
  output->append(statusMessage_);
  output->append("\r\n", 2);


  output->append("\r\n", 2);
}
