/*~--------------------------------------------------------------------------~*
 *  @@@@@@@@  @@           @@@@@@   @@@@@@@@ @@
 * /@@/////  /@@          @@////@@ @@////// /@@
 * /@@       /@@  @@@@@  @@    // /@@       /@@
 * /@@@@@@@  /@@ @@///@@/@@       /@@@@@@@@@/@@
 * /@@////   /@@/@@@@@@@/@@       ////////@@/@@
 * /@@       /@@/@@//// //@@    @@       /@@/@@
 * /@@       @@@//@@@@@@ //@@@@@@  @@@@@@@@ /@@
 * //       ///  //////   //////  ////////  //
 *
 * Copyright (c) 2016 Los Alamos National Laboratory, LLC
 * All rights reserved
 *~--------------------------------------------------------------------------~*/

#ifndef flecsi_default_scoped_h
#define flecsi_default_scoped_h

#include "flecsi/utils/const_string.h"
#include "flecsi/data/default/default_storage_type.h"

/*!
 * \file default_scoped.h
 * \authors bergen
 * \date Initial file creation: Apr 17, 2016
 */

namespace flecsi
{
namespace data_model
{
namespace default_storage_policy
{

  /*!
    FIXME: Scoped storage type.
   */
  template<typename data_store_t, typename meta_data_t>
  struct storage_type_t<scoped, data_store_t, meta_data_t> {

    struct scoped_accessor_t {
    }; // struct scoped_accessor_t

    struct scoped_handle_t {
    }; // struct scoped_handle_t

    template<typename T, size_t NS, typename ... Args>
    static decltype(auto) register_data(data_store_t & data_store,
      uintptr_t runtime_namespace, const const_string_t & key,
      size_t indeces, Args && ... args) {
    } // register_data

    /*!
     */
    template<typename T, size_t NS>
    static scoped_accessor_t get_accessor(data_store_t & data_store,
      uintptr_t runtime_namespace, const const_string_t & key) {
      return {};
    } // get_accessor

    /*!
     */
    template<typename T, size_t NS>
    static scoped_handle_t get_handle(data_store_t & data_store,
      uintptr_t runtime_namespace, const const_string_t & key) {
      return {};
    } // get_handle

  }; // struct storage_type_t

} // namespace default_storage_policy
} // namespace data_model
} // namespace flecsi

#endif // flecsi_default_scoped_h

/*~-------------------------------------------------------------------------~-*
 * Formatting options
 * vim: set tabstop=2 shiftwidth=2 expandtab :
 *~-------------------------------------------------------------------------~-*/
