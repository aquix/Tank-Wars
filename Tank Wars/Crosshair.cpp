#include "Crosshair.h"
#include <string>

Crosshair::Crosshair(Vector2f pos, Texture &tex, IntRect rect) :
GameObject(pos, tex, rect)
{
    font.loadFromFile(MAIN_FONT);

    timeBeforeShoot.setFont(font);
    timeBeforeShoot.setCharacterSize(20);

    tankInfo.setFont(font);
    tankInfo.setCharacterSize(20);

    isVisible = true;
}


void Crosshair::update(Vector2f pos, std::list<Enemy*> &enemies, Player &player)
{
    // �� ��������� ������ �� ��������� ��� ��������.
    tankInfo.setString("");

    // ���� ������� �� ��������� - �����.
    sprite.setColor(Color::White);

    // ���� ������ ������ �� ����� - ���� �������.
    for (std::list<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it) {
        GameObject *obj = *it;
        if (checkCollision(obj) == true) {
            sprite.setColor(Color::Red);

            tankInfo.setString((*it)->getTankInfo());
            tankInfo.setColor(Color::Red);
        }
    }

    // ���� ������ ������ �� ������ - ���� ������.
    GameObject *obj = &player;
    if (checkCollision(obj) == true) {
        sprite.setColor(Color::Blue);

        std::wstring temp = player.getTankInfo();
        tankInfo.setString(player.getTankInfo());
        tankInfo.setColor(Color::Blue);
    }
    sprite.setPosition(pos.x, pos.y);

    if (player.getReaminingTime() != 0) {
        timeBeforeShoot.setColor(Color::Red);
        timeBeforeShoot.setString(numToStr(player.getReaminingTime()));
    } else {
        timeBeforeShoot.setString("");
    }
    tankInfo.setPosition(pos.x - 36, pos.y - 36);
    timeBeforeShoot.setPosition(pos.x + 8, pos.y + 8);
}

void Crosshair::draw(RenderWindow &window)
{
    if (isVisible) {
        GameObject::draw(window);
        window.draw(timeBeforeShoot);
        window.draw(tankInfo);
    }
}

void Crosshair::setVisibility(bool visibility) {
    isVisible = visibility;
}