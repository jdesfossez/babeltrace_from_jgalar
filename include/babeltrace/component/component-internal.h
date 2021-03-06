#ifndef BABELTRACE_COMPONENT_COMPONENT_INTERNAL_H
#define BABELTRACE_COMPONENT_COMPONENT_INTERNAL_H

/*
 * BabelTrace - Component internal
 *
 * Copyright 2015 Jérémie Galarneau <jeremie.galarneau@efficios.com>
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

#include <babeltrace/babeltrace-internal.h>
#include <babeltrace/component/component.h>
#include <babeltrace/component/component-class-internal.h>
#include <babeltrace/component/component-port-internal.h>
#include <babeltrace/object-internal.h>
#include <glib.h>
#include <stdio.h>

#define DEFAULT_INPUT_PORT_NAME		"default"
#define DEFAULT_OUTPUT_PORT_NAME	"default"

struct bt_component {
	struct bt_object base;
	struct bt_component_class *class;
	GString *name;

	/**
	 * Internal destroy function specific to a source, filter, or
	 * sink component object.
	 */
	bt_component_class_destroy_method destroy;

	/** User-defined data */
	void *user_data;

	/**
	 * Used to protect operations which may only be used during
	 * a component's initialization.
	 */
	bool initializing;
};

BT_HIDDEN
enum bt_component_status bt_component_init(struct bt_component *component,
		bt_component_class_destroy_method destroy);

BT_HIDDEN
struct bt_notification_iterator *bt_component_create_iterator(
		struct bt_component *component, void *init_method_data);

BT_HIDDEN
enum bt_component_status bt_component_new_connection(
		struct bt_component *component, struct bt_port *own_port,
		struct bt_connection *connection);

BT_HIDDEN
void bt_component_set_graph(struct bt_component *component,
		struct bt_graph *graph);

BT_HIDDEN
int bt_component_init_input_ports(struct bt_component *component,
		GPtrArray **input_ports);

BT_HIDDEN
int bt_component_init_output_ports(struct bt_component *component,
		GPtrArray **output_ports);

BT_HIDDEN
struct bt_port *bt_component_get_port(GPtrArray *ports, const char *name);

BT_HIDDEN
struct bt_port *bt_component_get_port_at_index(GPtrArray *ports, int index);

BT_HIDDEN
struct bt_port *bt_component_add_port(
		struct bt_component *component,GPtrArray *ports,
		enum bt_port_type port_type, const char *name);

BT_HIDDEN
enum bt_component_status bt_component_remove_port(
		struct bt_component *component, GPtrArray *ports,
		const char *name);

#endif /* BABELTRACE_COMPONENT_COMPONENT_INTERNAL_H */
