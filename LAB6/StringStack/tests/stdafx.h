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

#define BOOST_TEST_MODULE Lab5-Tests
#define BOOST_TEST_INCLUDED
#include <boost\test\unit_test.hpp>
#include <boost\test\output_test_stream.hpp>
using boost::test_tools::output_test_stream;