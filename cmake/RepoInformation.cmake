include(GitInformation)

if(GIT_FOUND)
	git_check_repository(GIT_REPO_FOUND)
	if(GIT_REPO_FOUND)
		git_commit_hash(GIT_COMMIT_HASH GIT_COMMIT_HASH_SHORT)
		git_branch_name(GIT_BRANCH)
		message(STATUS "git branch: ${GIT_BRANCH}")
		message(STATUS "git commit hash: ${GIT_COMMIT_HASH}")

		# version handling if repository information is available
		if(NOT ("${CMAKE_BUILD_TYPE}" MATCHES "Release"))
			set(PROJECT_VERSION "${PROJECT_VERSION}-${GIT_COMMIT_HASH_SHORT}")
		endif()
	else()
		message(STATUS "no git repository found, no further version info available")
	endif()
else()
	message(STATUS "git not found, no further version info available")
endif()
message(STATUS "Project Vesion: ${PROJECT_VERSION}")
