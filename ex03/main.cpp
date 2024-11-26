/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <sdell-er@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 23:26:05 by sdell-er          #+#    #+#             */
/*   Updated: 2024/11/24 23:47:05 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	Point a(0, 0);
	Point b(0, 1);
	Point c(1, 0);

	Point inside_point1(0.2f, 0.2f);
	Point inside_point2(0.5f, 0.45f);
	Point outside_point(2, 2);
	Point edge_point(0.5f, 0);

	std::cout << "Inside point1: " << bsp(a, b, c, inside_point1) << std::endl;
	std::cout << "Inside point2: " << bsp(a, b, c, inside_point2) << std::endl;
	std::cout << "Outside point: " << bsp(a, b, c, outside_point) << std::endl;
	std::cout << "Edge point: " << bsp(a, b, c, edge_point) << std::endl;
	std::cout << "Vertex: " << bsp(a, b, c, a) << std::endl;
}
