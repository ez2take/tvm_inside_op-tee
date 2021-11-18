CFG_TEE_TA_LOG_LEVEL ?= 4
# The UUID for the Trusted Application
BINARY=9d4b104f-840c-431b-ba18-01f7534f5ce8
-include $(TA_DEV_KIT_DIR)/mk/ta_dev_kit.mk
ldargs-$(BINARY).elf += tvm/standalone_crt/build/libgraph_executor.a
ldargs-$(BINARY).elf += tvm/standalone_crt/build/libcommon.a
ldargs-$(BINARY).elf += tvm/libtvm_model_ops.a
ifeq ($(wildcard $(TA_DEV_KIT_DIR)/mk/ta_dev_kit.mk), )
clean:
	@echo 'Note: $$(TA_DEV_KIT_DIR)/mk/ta_dev_kit.mk not found, cannot clean TA'
	@echo 'Note: TA_DEV_KIT_DIR=$(TA_DEV_KIT_DIR)'
endif
