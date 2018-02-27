#include <iostream>
#include <vector>

double calculate_block(std::vector<std::vector<std::vector<int>>> input, std::vector<std::vector<double>> filter, int row, int col, int stride) {
	int i, j;

	int input_row_start = row + stride - 1;
	int input_row_end = input_row_start + filter.size();

	int input_col_start = col + stride - 1;
	int input_col_end = input_col_start + filter[0].size();
	
	double value = 0.0;
	for(i = input_row_start; i < input_row_end; i++) {
		for(j = input_col_start; j < input_col_end; j++) {
			value += ((double)filter[i - input_row_start][j - input_col_start] * (double)input[0][i][j]);
		}
	}

	return value;
}

std::vector<std::vector<double>> conv_layer(std::vector<std::vector<std::vector<int>>> input, std::vector<std::vector<double>> filter, int stride) {
	double i, j, k;

	int filter_width = filter.size();
	int filter_height = filter[0].size();
	
	int input_width = input[0].size();
	int input_height = input[0][0].size();

	int output_matrix_width = input_width - filter_width + 1;
	int output_matrix_height = input_height - filter_height + 1;

	std::vector<std::vector<double>> output(output_matrix_width, std::vector<double>(output_matrix_height));

	for(i = 0; i < output_matrix_width; i++) {
		for(j = 0; j < output_matrix_height; j++) {
			output[i][j] = calculate_block(input, filter, i, j, stride);
		}
	}

	return output;
}

void print_output(std::vector<std::vector<double>> output) {
	double i, j;
	
	for(i = 0; i < output.size(); i++) {
		for(j = 0; j < output[0].size(); j++) {
			printf("[%f][%f]: %f\n", i, j, output[i][j]);
		}
	}
}

int main() {
	std::vector<std::vector<std::vector<int>>> test_data = 
	{
		{
			{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3},
			{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3},
			{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3},
			{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3},
			{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3},
			{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3},
			{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3},
			{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3},
			{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3},
			{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3},
			{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3},
			{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3},
			{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3},
			{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3},
			{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3},
			{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3}
		}
	};

	std::vector<std::vector<double>> filter = 
	{
		{1, 2, 1},
		{1, 2, 1},
		{1, 2, 1},
	};

	int stride = 1;

	std::vector<std::vector<double>> test_output = conv_layer(test_data, filter, stride);
	
	
	print_output(test_output);
	
	
	return 0;
}