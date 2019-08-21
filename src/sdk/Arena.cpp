#include "Arena.h"

Arena::Arena()
{
	for (uint8_t j = 0; j < SIZE; j++)
	{
		for (uint8_t i = 0; i < SIZE; i++)
		{
			blocks[i + j*SIZE].SetPosition(i, j);
		}
	}
	const auto SURR = Element::Type::SURR, PATH = Element::Type::PATH, OBS1 = Element::Type::OBS1, OBS2 = Element::Type::OBS2;
	Element::Type types[] =
	{
		SURR, SURR, SURR, SURR, SURR, SURR, SURR, SURR, SURR, SURR, SURR, SURR, SURR, SURR, SURR, SURR,
		SURR, PATH, OBS2, OBS1, OBS1, OBS2, OBS1, OBS2, OBS1, PATH, OBS1, OBS2, OBS1, OBS1, OBS1, SURR,
		SURR, PATH, PATH, OBS1, PATH, PATH, PATH, PATH, PATH, OBS1, OBS2, PATH, OBS1, PATH, OBS1, SURR,
		SURR, OBS1, PATH, OBS2, OBS1, OBS2, OBS1, OBS1, OBS1, PATH, PATH, OBS1, OBS2, OBS1, OBS2, SURR,
		SURR, PATH, PATH, PATH, PATH, OBS2, PATH, PATH, PATH, OBS2, PATH, PATH, PATH, PATH, OBS1, SURR,
		SURR, OBS1, OBS2, OBS1, OBS1, PATH, OBS2, OBS1, PATH, OBS1, OBS2, PATH, OBS2, OBS2, PATH, SURR,
		SURR, PATH, OBS1, OBS2, PATH, OBS1, PATH, PATH, PATH, PATH, OBS2, OBS1, OBS1, OBS1, PATH, SURR,
		SURR, OBS1, OBS1, PATH, OBS2, OBS2, PATH, OBS2, OBS2, PATH, OBS1, OBS1, PATH, PATH, OBS2, SURR,
		SURR, OBS2, PATH, PATH, OBS1, OBS1, PATH, OBS2, OBS2, PATH, OBS2, OBS2, PATH, OBS1, OBS1, SURR,
		SURR, PATH, OBS1, OBS1, OBS1, OBS2, PATH, PATH, PATH, PATH, OBS1, PATH, OBS2, OBS1, PATH, SURR,
		SURR, PATH, OBS2, OBS2, PATH, OBS2, OBS1, PATH, OBS1, OBS2, PATH, OBS1, OBS1, OBS2, OBS1, SURR,
		SURR, OBS1, PATH, PATH, PATH, PATH, OBS2, PATH, PATH, PATH, OBS2, PATH, PATH, PATH, PATH, SURR,
		SURR, OBS2, OBS1, OBS2, OBS1, PATH, PATH, OBS1, OBS1, OBS1, OBS2, OBS1, OBS2, PATH, OBS1, SURR,
		SURR, OBS1, PATH, OBS1, PATH, OBS2, OBS1, PATH, PATH, PATH, PATH, PATH, OBS1, PATH, PATH, SURR,
		SURR, OBS1, OBS1, OBS1, OBS2, OBS1, PATH, OBS1, OBS2, OBS1, OBS2, OBS1, OBS1, OBS2, PATH, SURR,
		SURR, SURR, SURR, SURR, SURR, SURR, SURR, SURR, SURR, SURR, SURR, SURR, SURR, SURR, SURR, SURR
	};
	for (uint16_t i = 0; i < SIZE*SIZE; i++)
	{
		blocks[i].SetType(types[i]);
	}
	players[0].SetPosition(1, 1);
	players[1].SetPosition(14, 14);
	players[1].SetType(Element::Type::PLR2);
}

void Arena::Update(float dt)
{
	for (auto &block : blocks)
	{
		simple_view[block.GetNormalizedPosition()] = block.GetTypeCode();
	}
	for (auto &bomb : bombs)
	{
		if (bomb.IsActive())
		{
			simple_view[bomb.GetNormalizedPosition()] = bomb.GetTypeCode();
		}
	}
	for (auto &player : players)
	{
		simple_view[player.GetNormalizedPosition()] = player.GetTypeCode();
	}
	for (auto &player : players)
	{
		player.Update(dt);
	}
	for (auto &bomb : bombs)
	{
		bomb.Update(dt);
	}
}

void Arena::Draw(uint32_t *drawer)
{
	for (uint16_t pos = 0; pos < SIZE*SIZE; pos++)
	{
		*drawer = (simple_view[pos] << 8) + pos;
	}
}
