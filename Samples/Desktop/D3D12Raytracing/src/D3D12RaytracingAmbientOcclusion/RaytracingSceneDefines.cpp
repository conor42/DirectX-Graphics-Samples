//*********************************************************
//
// Copyright (c) Microsoft. All rights reserved.
// This code is licensed under the MIT License (MIT).
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
//*********************************************************

#pragma once

#include "RayTracingSceneDefines.h"


namespace Scene
{
	const WCHAR* Type::Names[] = { L"Single object", L" Geometric forest", L"Squid room" };
	Params args[Scene::Type::Count];

	// Initialize scene parameters
	Initialize initializeObject;
	Initialize::Initialize()
	{
		// Camera Position
		{
			auto& camera = args[Scene::Type::SingleObject].camera;
#if TESSELATED_GEOMETRY_BOX
#if NUM_GEOMETRIES_1000
			camera.position.eye = { 0, (TESSELATED_GEOMETRY_TILES*TESSELATED_GEOMETRY_TILES_WIDTH + CAMERA_Y_SCALE) * 0.43f, 0, 1 };
#elif NUM_GEOMETRIES_100000
			camera.position.eye = { 0,  (TESSELATED_GEOMETRY_TILES*TESSELATED_GEOMETRY_TILES_WIDTH + CAMERA_Y_SCALE)*3.65f, 0, 1 };
#else
			camera.position.eye = { 0,  (TESSELATED_GEOMETRY_TILES*TESSELATED_GEOMETRY_TILES_WIDTH + CAMERA_Y_SCALE)*11.3f, 0, 1 };
#endif
			camera.position.at = { 0, 0, 0, 1 };
			camera.position.up = { 0, 0, 1, 0 };
#elif 1
			camera.position.eye = { 0.509415329f, 2.28009248f, -4.69469929f, 1 };
			camera.position.at = { 1.17371607f, -6.80418682f, 2.02239656f, 1 };
			camera.position.up = { 0.109009691f, 0.596148014f, 0.795441568f, 0};
#else
			camera.position.eye = { 0, 6.3f * CAMERA_Y_SCALE , -10.0f, 1 };
			camera.position.at = { 0, 1, 0, 1 };
			XMVECTOR right = { 1.0f, 0.0f, 0.0f, 0.0f };
			XMVECTOR forward = XMVector4Normalize(camera.position.at - camera.position.eye);
			camera.position.up = XMVector3Normalize(XMVector3Cross(forward, right));
#endif
			camera.boundaries.min = -XMVectorSplatInfinity();
			camera.boundaries.max = XMVectorSplatInfinity();
		}
		{
			// ToDo
			auto& camera = args[Scene::Type::GeometricForest].camera;
			camera.position.eye = { 0, 80, 268.555980f, 1 };
			camera.position.at = { 0, 80, 0, 1 };
			camera.position.up = { 0, 1, 0, 0 };
			camera.boundaries.min = -XMVectorSplatInfinity();
			camera.boundaries.max = XMVectorSplatInfinity();
		}
		{

			auto& camera = args[Scene::Type::SquidRoom].camera;
			camera.position.eye = { 0, 80, 268.555980f, 1 };
			camera.position.at = { 0, 80, 0, 1 };
			camera.position.up = { 0, 1, 0, 0 };
#if PBRT_SCENE
			camera.boundaries.min = -XMVectorSplatInfinity();
			camera.boundaries.max = XMVectorSplatInfinity();
#else
			camera.boundaries.min = { -430, 2.2f, -428, 1 };
			camera.boundaries.max = { 408, 358, 416, 1 };
#endif

#if DEBUG_CAMERA_POS
#if 0
            camera.position.eye = { -17.177f, 7.27362f, -12.6377f, 1 };
            camera.position.at = { -16.748f, 7.02274f, -11.7697f, 1 };
            camera.position.up = { 0.155454f, 0.933811f, 0.322219f, 0 };
#else
            camera.position.eye = { -27.2654f, 8.0924f, -9.16976f, 1 };
            camera.position.at = { -26.4939f, 7.89591f, -8.56419f, 1 };
            camera.position.up = { 0.237911f, 0.952311f, 0.191048f, 0 };
#endif
#endif
		}
	}
}
