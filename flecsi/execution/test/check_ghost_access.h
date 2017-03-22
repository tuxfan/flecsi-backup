/*~--------------------------------------------------------------------------~*
 * Copyright (c) 2017 Los Alamos National Security, LLC
 * All rights reserved.
 *~--------------------------------------------------------------------------~*/

#ifndef flecsi_execution_check_ghost_access_h
#define flecsi_execution_check_ghost_access_h

using namespace LegionRuntime::HighLevel;

#include <legion.h>
///
/// \file
/// \date Initial file creation: Mar 22, 2017
///

#define DH1 1
#undef flecsi_execution_legion_task_wrapper_h
#include "flecsi/execution/legion/task_wrapper.h"

#include <iostream>
#include <vector>

#include "flecsi/utils/common.h"
#include "flecsi/execution/context.h"
#include "flecsi/execution/execution.h"
#include "flecsi/data/data.h"
#include "flecsi/data/data_client.h"
#include "flecsi/data/legion/data_policy.h"
#include "flecsi/execution/legion/helper.h"

#include "flecsi/execution/test/mpilegion/sprint_common.h"

#include "flecsi/utils/const_string.h"


template<typename T>
using accessor_t = flecsi::data::legion::dense_accessor_t<T, flecsi::data::legion_meta_data_t<flecsi::default_user_meta_data_t> >;

void
task1(
  accessor_t<size_t> acc_cells
)
{
}


flecsi_register_task(task1, loc, single);

void
driver(
  int argc,
  char ** argv
)
{
  flecsi::execution::context_t & context_ = flecsi::execution::context_t::instance();
  const LegionRuntime::HighLevel::Task *task = context_.task(flecsi::utils::const_string_t{"driver"}.hash());
  const int my_color = task->index_point.point_data[0];
	std::cout << my_color << " check GHOST" << std::endl;

	flecsi::data_client& dc = *((flecsi::data_client*)argv[argc - 1]);

  int index_space = 0;
  auto h1 =
    flecsi_get_handle(dc, sprint, cell_ID, size_t, dense, index_space, rw, ro, ro);


  flecsi_execute_task(task1, loc, single, h1);
} //driver



#endif // flecsi_execution_check_ghost_access_h

/*~-------------------------------------------------------------------------~-*
 * Formatting options for vim.
 * vim: set tabstop=2 shiftwidth=2 expandtab :
 *~-------------------------------------------------------------------------~-*/
