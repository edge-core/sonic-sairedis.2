
#pragma once

#include "SwitchState.h"

namespace saivs
{
    class SwitchStateBase:
        public SwitchState
    {
        public:

            SwitchStateBase(
                    _In_ sai_object_id_t switch_id);

            virtual ~SwitchStateBase() = default;

        public: // TODO to protected

            virtual sai_status_t set_switch_mac_address();

            virtual sai_status_t set_switch_default_attributes();

            virtual sai_status_t create_default_vlan();

            virtual sai_status_t create_cpu_port();

            virtual sai_status_t create_default_1q_bridge();

            virtual sai_status_t create_ports();

            virtual sai_status_t set_port_list();

            virtual sai_status_t create_default_virtual_router();

            virtual sai_status_t create_default_stp_instance();

            virtual sai_status_t create_default_trap_group();

            virtual sai_status_t create_ingress_priority_groups_per_port(
                    _In_ sai_object_id_t switch_id,
                    _In_ sai_object_id_t port_id);

            virtual sai_status_t create_ingress_priority_groups();

            virtual sai_status_t create_vlan_members();

        protected:

            virtual sai_status_t create(
                    _In_ sai_object_type_t object_type,
                    _Out_ sai_object_id_t *object_id,
                    _In_ sai_object_id_t switch_id,
                    _In_ uint32_t attr_count,
                    _In_ const sai_attribute_t *attr_list);

            virtual sai_status_t set(
                    _In_ sai_object_type_t objectType,
                    _In_ sai_object_id_t objectId,
                    _In_ const sai_attribute_t* attr);

        public: // TODO to proctected

            std::vector<sai_object_id_t> m_port_list;
            std::vector<sai_object_id_t> m_bridge_port_list_port_based;

            std::vector<sai_acl_action_type_t> ingress_acl_action_list;
            std::vector<sai_acl_action_type_t> m_egress_acl_action_list;

            sai_object_id_t m_default_vlan_id;

            sai_object_id_t m_cpu_port_id;

    };
}
