#pragma once

#include <text_mining/parse_string.h>

void graph_hash_of_mixed_weighted_read_for_GSTP(std::string instance_name,
												graph_hash_of_mixed_weighted &input_graph, graph_hash_of_mixed_weighted &group_graph,
												std::unordered_set<int> &group_vertices)
{

	input_graph.clear();
	group_graph.clear();
	group_vertices.clear();

	std::string line_content;
	std::ifstream myfile(instance_name); // open the file
	if (myfile.is_open())				 // if the file is opened successfully
	{
		while (getline(myfile, line_content)) // read file line by line
		{
			std::vector<std::string> Parsed_content = parse_string(line_content, " ");

			if (!Parsed_content[0].compare("input_graph") && !Parsed_content[1].compare("Vertex"))
			// when it's equal, compare returns 0
			{

				int v = std::stoi(Parsed_content[2]);
               \
				int nw = std::stoi(Parsed_content[3]);
				graph_hash_of_mixed_weighted_add_vertex(input_graph, v, nw);
			}
			else if (!Parsed_content[0].compare("input_graph") && !Parsed_content[1].compare("Edge"))
			{
				int v1 = std::stoi(Parsed_content[2]);
				int v2 = std::stoi(Parsed_content[3]);
				int ec = std::stoi(Parsed_content[4]);
				graph_hash_of_mixed_weighted_add_edge(input_graph, v1, v2, ec);
			}
			else if (!Parsed_content[0].compare("group_graph") && !Parsed_content[1].compare("Vertex"))
			{
				int v = std::stoi(Parsed_content[2]);
				int nw = std::stoi(Parsed_content[3]);
				graph_hash_of_mixed_weighted_add_vertex(group_graph, v, nw);
			}
			else if (!Parsed_content[0].compare("group_graph") && !Parsed_content[1].compare("Edge"))
			{
				int v1 = std::stoi(Parsed_content[2]);
				int v2 = std::stoi(Parsed_content[3]);
				int ec = std::stoi(Parsed_content[4]);
				graph_hash_of_mixed_weighted_add_edge(group_graph, v1, v2, ec);
			}
			else if (!Parsed_content[0].compare("group_vertices"))
			{
				int g = std::stoi(Parsed_content[1]);
				group_vertices.insert(g);
			}

		}

		myfile.close(); // close the file
	}
	else
	{
		std::cout << "Unable to open file " << instance_name << std::endl
				  << "Please check the file location or file name." << std::endl; // throw an error message
		getchar();																  // keep the console window
		exit(1);																  // end the program
	}
}
