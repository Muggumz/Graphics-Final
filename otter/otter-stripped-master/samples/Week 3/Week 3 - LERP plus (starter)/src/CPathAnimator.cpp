/*
NOU Framework - Created for INFR 2310 at Ontario Tech.
(c) Samantha Stahlke 2020

CPathAnimator.cpp
Simple component for animating an object along a path.

As a convention in NOU, we put "C" before a class name to signify
that we intend the class for use as a component with the ENTT framework.
*/

#include "CPathAnimator.h"
#include <iostream>


namespace nou
{
	CPathAnimator::CPathAnimator(Entity& owner)
	{
		m_owner = &owner;

		m_segmentIndex = 0;
		m_segmentTimer = 0.0f;

		//Accurate Names
		m_scuffed = 0;
		m_scuffeder = 1;

		m_segmentTravelTime = 1.0f;
		m_mode = PathSampler::PathMode::LERP;
	}

	void CPathAnimator::SetMode(PathSampler::PathMode mode)
	{
		m_mode = mode;
		m_segmentIndex = 0;
	}

	//member to access LERP really scuffed
	PathSampler k;
	int test = 0;
	
	void CPathAnimator::Update(const PathSampler::KeypointSet& keypoints, float deltaTime)
	{
		// TODO: Implement this function
		// Steps to follow:

		// Make sure we have points to use
		
		
		// Increment our t value

	
		
		// Handle switching segments each time t = 1

		// Work out t using segment timer and segment travel time

		// Ensure we have at least 2 points to LERP along
		// Need at least 2 points for 1 segment

		// Determine the indexes of the points to LERP along (in our vector of key points)

		// Perform LERP using function in PathSampler
		if (keypoints.size()>1)
		{
			//time checker
			
			std::cout << m_segmentTimer << std::endl;


			if(keypoints.size()==2)
			{
				if (increaser == true)
				{
					m_segmentTimer += 0.1f;
				}
				else if (increaser == false)
				{
					m_segmentTimer -= 0.1f;
				}

				if (m_segmentTimer >= 1.f)
				{
					increaser = false;
				}
				else if (m_segmentTimer <= 0.1f)
				{
					increaser = true;
				}
			}
			else if (keypoints.size() > 2)
			{
				m_segmentTimer += 0.1f;

				if (0.95< m_segmentTimer)
				{
					m_segmentTimer = 0;

					test = m_scuffed + 1;
					
					if (test == keypoints.size())
					{
						m_scuffed = 0;
					}
					else
					{
						m_scuffed++;
					}
					
					test = m_scuffed + 1;

					if (test == keypoints.size())
					{
						m_scuffeder = 0;
					}
					else
					{
						m_scuffeder++;
					}
				}
			}
			

			
			m_owner->transform.m_pos.x = k.LERP(keypoints[m_scuffed]->transform.m_pos.x, keypoints[m_scuffeder]->transform.m_pos.x, m_segmentTimer);
			m_owner->transform.m_pos.y = k.LERP(keypoints[m_scuffed]->transform.m_pos.y, keypoints[m_scuffeder]->transform.m_pos.y, m_segmentTimer);
			m_owner->transform.m_pos.z = k.LERP(keypoints[m_scuffed]->transform.m_pos.z, keypoints[m_scuffeder]->transform.m_pos.z, m_segmentTimer);
		}
		
	}
}