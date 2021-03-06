#pragma once

#include "envoy/extensions/filters/network/ext_authz/v3alpha/ext_authz.pb.h"
#include "envoy/extensions/filters/network/ext_authz/v3alpha/ext_authz.pb.validate.h"

#include "extensions/filters/network/common/factory_base.h"
#include "extensions/filters/network/well_known_names.h"

namespace Envoy {
namespace Extensions {
namespace NetworkFilters {
namespace ExtAuthz {

/**
 * Config registration for the  external authorization filter. @see NamedNetworkFilterConfigFactory.
 */
class ExtAuthzConfigFactory
    : public Common::FactoryBase<
          envoy::extensions::filters::network::ext_authz::v3alpha::ExtAuthz> {
public:
  ExtAuthzConfigFactory() : FactoryBase(NetworkFilterNames::get().ExtAuthorization) {}

private:
  Network::FilterFactoryCb createFilterFactoryFromProtoTyped(
      const envoy::extensions::filters::network::ext_authz::v3alpha::ExtAuthz& proto_config,
      Server::Configuration::FactoryContext& context) override;
};

} // namespace ExtAuthz
} // namespace NetworkFilters
} // namespace Extensions
} // namespace Envoy
