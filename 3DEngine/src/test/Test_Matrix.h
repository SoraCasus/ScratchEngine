#pragma once

#include "../util/math/Math.h"

bool MatrixConstruct()
{
	math::Matrix<4, 4, float> test01();
	math::Matrix<3, 3, double> test02({ 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 });
	math::Vector<3, double> test03 = test02.col[0];

	return true;
}

bool MatrixIndexing()
{

	bool success = true;

	math::Matrix<4, 3, float> matrix({
		1.0F, 2.0F, 3.0F, 4.0F,
		5.0F, 6.0F, 7.0F, 8.0F,
		9.0F, 10.0F, 11.0F, 12.0F
	});

	math::Vector<4, float> vector({ 1.0F, 2.0F, 3.0F, 4.0F });

	if (matrix[0][0] != 1.0f) success = false;
	if (matrix[0][1] != 2.0f) success = false;
	if (matrix[0][2] != 3.0f) success = false;
	if (matrix[0][3] != 4.0f) success = false;
	if (matrix[1][0] != 5.0f) success = false;
	if (matrix[1][1] != 6.0f) success = false;
	if (matrix[1][2] != 7.0f) success = false;
	if (matrix[1][3] != 8.0f) success = false;
	if (matrix[2][0] != 9.0f) success = false;
	if (matrix[2][1] != 10.0f) success = false;
	if (matrix[2][2] != 11.0f) success = false;
	if (matrix[2][3] != 12.0f) success = false;

	math::Vector<2, float> vector01({ 1.0f, 2.0f });
	math::Vector<2, float> vector02({ 3.0f, 4.0f });
	math::Matrix<2, 2, float> matrix22;
	matrix22[0] = vector01;
	matrix22[1] = vector02;

	if (matrix22[0][0] != 1.0f) success = false;
	if (matrix22[0][1] != 2.0f) success = false;
	if (matrix22[1].x != 3.0f) success = false;
	if (matrix22[1].y != 4.0f) success = false;

	return success;


}



