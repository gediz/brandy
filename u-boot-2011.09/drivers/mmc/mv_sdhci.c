/*
 * drivers/mmc/mv_sdhci.c
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#include <common.h>
#include <malloc.h>
#include <sdhci.h>

static char *MVSDH_NAME = "mv_sdh";
int mv_sdh_init(u32 regbase, u32 max_clk, u32 min_clk, u32 quirks)
{
	struct sdhci_host *host = NULL;
	host = (struct sdhci_host *)malloc(sizeof(struct sdhci_host));
	if (!host) {
		printf("sdh_host malloc fail!\n");
		return 1;
	}

	host->name = MVSDH_NAME;
	host->ioaddr = (void *)regbase;
	host->quirks = quirks;
	host->version = sdhci_readw(host, SDHCI_HOST_VERSION);
	add_sdhci(host, max_clk, min_clk);
	return 0;
}
