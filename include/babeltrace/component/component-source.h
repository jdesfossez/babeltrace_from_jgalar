#ifndef BABELTRACE_COMPONENT_SOURCE_H
#define BABELTRACE_COMPONENT_SOURCE_H

/*
 * BabelTrace - Source Plug-in Interface
 *
 * Copyright 2016 Jérémie Galarneau <jeremie.galarneau@efficios.com>
 *
 * Author: Jérémie Galarneau <jeremie.galarneau@efficios.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdint.h>
#include <babeltrace/component/component.h>

#ifdef __cplusplus
extern "C" {
#endif

struct bt_component;
struct bt_notification_iterator;

/* FIXME should return a bt_component_status, same applies for filter and sink. Use uint64_t. */
extern int bt_component_source_get_output_port_count(
		struct bt_component *component);
extern struct bt_port *bt_component_source_get_output_port(
		struct bt_component *component, const char *name);
extern struct bt_port *bt_component_source_get_output_port_at_index(
		struct bt_component *component, int index);
extern struct bt_port *bt_component_source_get_default_output_port(
		struct bt_component *component);

/* Only allowed during the source's initialization. */
extern struct bt_port *bt_component_source_add_output_port(
		struct bt_component *component, const char *name);
/* Only allowed during the source's initialization. */
extern enum bt_component_status bt_component_source_remove_output_port(
		struct bt_component *component, const char *name);

#ifdef __cplusplus
}
#endif

#endif /* BABELTRACE_COMPONENT_SOURCE_H */
