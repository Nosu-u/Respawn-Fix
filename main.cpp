// credit to FigmentBoy!!
#include <Geode.hpp>

int smoothOut = 0;

USE_GEODE_NAMESPACE();

class $(PlayLayer) {
	void resetLevel() {
		if (m_isTestMode || m_isPracticeMode) {
			smoothOut = 2;
		}
		return PlayLayer::resetLevel();
	}

	void update(float dt) {
		if (!smoothOut) {
			return update(dt);
		}

		float time = cocos2d::CCDirector::sharedDirector()->getAnimationInterval();
		if (smoothOut != 0 && dt - time < 1) {
			smoothOut --;
		}

		return PlayLayer::update(time);

	}
};