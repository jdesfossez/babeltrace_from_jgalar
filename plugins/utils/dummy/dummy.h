#ifndef BABELTRACE_PLUGINS_UTILS_DUMMY_H
#define BABELTRACE_PLUGINS_UTILS_DUMMY_H

/*
 * Copyright 2017 Philippe Proulx <pproulx@efficios.com>
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

#include <glib.h>
#include <babeltrace/component/component.h>
#include <babeltrace/component/component-port.h>
#include <babeltrace/component/component-connection.h>

struct dummy {
	GPtrArray *iterators;
};

enum bt_component_status dummy_init(struct bt_component *component,
		struct bt_value *params, void *init_method_data);
void dummy_destroy(struct bt_component *component);
enum bt_component_status dummy_new_connection(struct bt_port *own_port,
		struct bt_connection *connection);
enum bt_component_status dummy_consume(struct bt_component *component);

#endif /* BABELTRACE_PLUGINS_UTILS_DUMMY_H */
