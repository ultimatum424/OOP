// stdafx.h: ���������� ���� ��� ����������� ��������� ���������� ������
// ��� ���������� ������ ��� ����������� �������, ������� ����� ������������, ��
// �� ����� ����������
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include "../StringStack/stdafx.h"



// TODO: ���������� ����� ������ �� �������������� ���������, ����������� ��� ���������

#include <boost/algorithm/string/replace.hpp>
#pragma warning (disable: 4702)
#define BOOST_TEST_INCLUDED
#include <boost\test\unit_test.hpp>
#include <boost\test\output_test_stream.hpp>
using boost::test_tools::output_test_stream;